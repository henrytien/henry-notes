using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ice.ProjectCos.Util
{
    public sealed class Trigger<Key, T1, T2>
    {
        private Dictionary<Key, Action<Key, T1, T2>> triggers_ = new Dictionary<Key, Action<Key, T1, T2>>();

        public void AddTriggerEvent(Key type, Action<Key, T1, T2> trigger)
        {
            Action<Key, T1, T2> t;
            if (!triggers_.TryGetValue(type, out t))
            {
                triggers_.Add(type, trigger);
            }
            else
            {
                t += trigger;
                triggers_[type] = t;
            }
        }

        public void RemoveTriggerEvent(Key type, Action<Key, T1, T2> trigger)
        {
            Action<Key, T1, T2> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t -= trigger;

                if (t == null)
                {
                    triggers_.Remove(type);
                }
                else
                {
                    triggers_[type] = t;
                }
            }
        }

        public void InvokeTriggerEvent(Key type, T1 t1 = default(T1), T2 t2 = default(T2))
        {
            Action<Key, T1, T2> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t(type, t1, t2);
            }
        }
    }

    public sealed class Trigger<Key, T1, T2, T3>
    {
        private Dictionary<Key, Action<Key, T1, T2, T3>> triggers_ = new Dictionary<Key, Action<Key, T1, T2, T3>>();

        public void AddTriggerEvent(Key type, Action<Key, T1, T2, T3> trigger)
        {
            Action<Key, T1, T2, T3> t;
            if (!triggers_.TryGetValue(type, out t))
            {
                triggers_.Add(type, trigger);
            }
            else
            {
                t += trigger;
                triggers_[type] = t;
            }
        }

        public void RemoveTriggerEvent(Key type, Action<Key, T1, T2, T3> trigger)
        {
            Action<Key, T1, T2, T3> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t -= trigger;

                if (t == null)
                {
                    triggers_.Remove(type);
                }
                else
                {
                    triggers_[type] = t;
                }
            }
        }

        public void InvokeTriggerEvent(Key type, T1 t1 = default(T1), T2 t2 = default(T2), T3 t3 = default(T3))
        {
            Action<Key, T1, T2, T3> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t(type, t1, t2, t3);
            }
        }
    }

    public sealed class Trigger<Key, T1, T2, T3, T4>
    {
        private Dictionary<Key, Action<Key, T1, T2, T3, T4>> triggers_ = new Dictionary<Key, Action<Key, T1, T2, T3, T4>>();

        public void AddTriggerEvent(Key type, Action<Key, T1, T2, T3, T4> trigger)
        {
            Action<Key, T1, T2, T3, T4> t;
            if (!triggers_.TryGetValue(type, out t))
            {
                triggers_.Add(type, trigger);
            }
            else
            {
                t += trigger;
                triggers_[type] = t;
            }
        }

        public void RemoveTriggerEvent(Key type, Action<Key, T1, T2, T3, T4> trigger)
        {
            Action<Key, T1, T2, T3, T4> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t -= trigger;

                if (t == null)
                {
                    triggers_.Remove(type);
                }
                else
                {
                    triggers_[type] = t;
                }
            }
        }

        public void InvokeTriggerEvent(Key type, T1 t1 = default(T1), T2 t2 = default(T2), T3 t3 = default(T3), T4 t4 = default(T4))
        {
            Action<Key, T1, T2, T3, T4> t;
            if (triggers_.TryGetValue(type, out t))
            {
                t(type, t1, t2, t3, t4);
            }
        }
    }
}
