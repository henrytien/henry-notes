## 简单动态字符串	

![](./img/cstring_vs_sds.png)

**Sds 的优点**：

1. 常数获取字符串长度
2. 避免缓冲区溢出
3. 减少修改字符串长度的内存分配次数
4. 二进制安全

## 链表

双端链表结构

```c
/*
 * 双端链表结构
 */
typedef struct list {
    // 表头节点
    listNode *head;
    // 表尾节点
    listNode *tail;
    // 节点值复制
    void *(*dup)(void *ptr);
    // 节点值释放
    void (*free)(void *ptr);
    // 节点值比较函数
    int (*match)(void *ptr, void *key);
    unsigned long len;
} list;
```

Many fuction implement by list. 

![](./img/listnode.png)

## 字典

### Hash table	

Dict is an implementation of a non-blocking hash table which rehashes incrementally.

```c
typedef struct dict {
    dictEntry **table;
    dictType *type;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
    void *privdata;
} dict;
```

<img src="./img/empty_table.png" style="zoom:50%;" />

Hash  table node.

```c
typedef struct dictIterator {
    dict *ht;
    int index;
    dictEntry *entry, *nextEntry;
} dictIterator;
```

### Hash collision

Redis 的哈希表使用链地址法（separate chaining）来解决键冲突： 每个哈希表节点都有一个 `next` 指针， 多个哈希表节点可以用 `next` 指针构成一个单向链表， 被分配到同一个索引上的多个节点可以用这个单向链表连接起来， 这就解决了键冲突的问题。

> **Solution 1: Store data of different modules in different Redis instances**
>
> **Solution 2: Store data of different modules in different databases of a single Redis instance**
>
> **Solution 3: Create namespace with key prefix**

[How to namespace keys on redis to avoid name collisions?](https://stackoverflow.com/questions/39192469/how-to-namespace-keys-on-redis-to-avoid-name-collisions) 

```c
typedef struct dict {
    dictType *type;
    void *privdata;
    // hashtable first use ht[0]，when rehash use ht[1]
    dictht ht[2];
    long rehashidx; /* rehashing not in progress if rehashidx == -1 */
    unsigned long iterators; /* number of iterators currently running */
} dict;
```

 Redis usually stores data in the first `dictht` instance ( `ht[0]` ). While rehashing, it creates an expanded hash table of size power of 2 just greater than or equal to the current hash table ( `ht[0]` ) size and the new hash table is actually stored in `ht[1]` instance.



### Redis rehash

Redis 对字典的哈希表执行 rehash 的步骤如下：

1. 为字典的 `ht[1]` 哈希表分配空间， 这个哈希表的空间大小取决于要执行的操作， 以及 `ht[0]`

    当前包含的键值对数量 （也即是`ht[0].used` 属性的值）：

   - 如果执行的是扩展操作， 那么 `ht[1]` 的大小为第一个大于等于 `ht[0].used * 2` 的 ![2^n](https://atts.w3cschool.cn/attachments/image/cimg/2015-09-13_55f512f991fc2.png) （`2` 的 `n` 次方幂）；
   - 如果执行的是收缩操作， 那么 `ht[1]` 的大小为第一个大于等于 `ht[0].used` 的 ![2^n](https://atts.w3cschool.cn/attachments/image/cimg/2015-09-13_55f512f991fc2.png) 。

2. 将保存在 `ht[0]` 中的所有键值对 rehash 到 `ht[1]` 上面： rehash 指的是重新计算键的哈希值和索引值， 然后将键值对放置到 `ht[1]` 哈希表的指定位置上。

3. 当 `ht[0]` 包含的所有键值对都迁移到了 `ht[1]` 之后 （`ht[0]` 变为空表）， 释放 `ht[0]` ， 将 `ht[1]` 设置为 `ht[0]` ， 并在 `ht[1]` 新创建一个空白哈希表， 为下一次 rehash 做准备。

hash factor, `load_factor = ht[0].used / ht[0].size`.

### 渐进式 rehash 

因为在进行渐进式 rehash 的过程中， 字典会同时使用 `ht[0]` 和 `ht[1]` 两个哈希表， 所以在渐进式 rehash 进行期间， 字典的删除（delete）、查找（find）、更新（update）等操作会在两个哈希表上进行： 比如说， 要在字典里面查找一个键的话， 程序会先在 `ht[0]` 里面进行查找， 如果没找到的话， 就会继续到 `ht[1]` 里面进行查找.

### Hash function 

Hash function is [MurmurHash2](https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp), It was created by Austin Appleby in 2008[[2\]](https://en.wikipedia.org/wiki/MurmurHash#cite_note-2) and is currently hosted on GitHub along with its test suite named 'SMHasher'.

Redis conclude











