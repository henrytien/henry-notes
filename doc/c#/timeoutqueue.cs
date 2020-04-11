using System;
using System.Collections.Generic;
using System.Linq;

namespace Ice.Utils {
  /// <summary>
  /// https://github.com/facebook/folly/blob/master/folly/TimeoutQueue.h
  /// </summary>
  public sealed class TimeoutQueue {
    private sealed class Event {
      public int Id;
      public long Expiration;
      public long RepeatInterval;
      public Action<int, long> Callback;
      public LinkedListNode<Event> LinkNode;
    }

    private int nextId_ = 1;
    private Dictionary<int, Event> ids_ = new Dictionary<int, Event>();
    private LinkedList<Event> events_ = new LinkedList<Event>();

    private int NextId {
      get { return unchecked(nextId_++); }
    }

    private void Insert(Event e) {
      ids_.Add(e.Id, e);
      Event next = events_.FirstOrDefault(i => i.Expiration > e.Expiration);
      if (next != null) {
        e.LinkNode = events_.AddBefore(next.LinkNode, e);
      }
      else {
        e.LinkNode = events_.AddLast(e);
      }
    }

    public int Add(long now, long delay, Action<int, long> callback) {
      return AddRepeating(now, delay, 0, callback);
    }

    public int AddRepeating(long now, long interval, Action<int, long> callback) {
      return AddRepeating(now, interval, interval, callback);
    }

    public int AddRepeating(long now, long delay, long interval, Action<int, long> callback) {
      int id = NextId;
      Insert(new Event() {
        Id = id,
        Expiration = now + delay,
        RepeatInterval = interval,
        Callback = callback
      });
      return id;
    }

    public long NextExpiration {
      get {
        return events_.Count > 0 ? events_.First.Value.Expiration : long.MaxValue;
      }
    }

    public bool Erase(int id) {
      Event e = ids_.GetOrDefault(id);
      if (e != null) {
        ids_.Remove(id);
        events_.Remove(e.LinkNode);
        return true;
      }
      return false;
    }

    public long RunOnce(long now) {
      return RunInternal(now, true);
    }

    public long RunLoop(long now) {
      return RunInternal(now, false);
    }

    public int Count {
      get {
        return ids_.Count;
      }
    }

    public bool Contains(int id) {
      return ids_.ContainsKey(id);
    }

    private long RunInternal(long now, bool onceOnly) {
      long nextExp;
      do {
        List<Event> expired = events_.TakeWhile(i => i.Expiration <= now).ToList();
        foreach (Event e in expired) {
          Erase(e.Id);
          if (e.RepeatInterval > 0) {
            e.Expiration += e.RepeatInterval;
            Insert(e);
          }
        }
        foreach (Event e in expired) {
          e.Callback(e.Id, now);
        }
        nextExp = NextExpiration;
      } while (!onceOnly && nextExp <= now);
      return nextExp;
    }
  }
}
