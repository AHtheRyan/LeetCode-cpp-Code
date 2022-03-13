### LRU缓存
### LRU Cache

> 请你设计并实现一个满足`LRU (最近最少使用) 缓存`约束的数据结构。  
> 实现 `LRUCache` 类：  
> - `LRUCache(int capacity)` 以**正整数**作为容量 `capacity` 初始化LRU缓存  
> - `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1`。  
> - `void put(int key, int value)` 如果关键字 `key` 已经存在，则变更其数据值 `value`；如果不存在，则向缓存中插入该组 `key-value`。如果插入操作导致关键字数量超过 `capacity`，则应该**逐出**最久未使用的关键字。  
> 
> 函数 `get` 和 `put` 必须以 `O(1)` 的平均时间复杂度运行。  

> Design a data structure that follows the constraints of a `Least Recently Used (LRU) cache`.  
> Implement the `LRUCache` class:  
> - `LRUCache(int capacity)` Initialize the LRU cache with **positive** size `capacity`.  
> - `int get(int key)` Return the value of the `key` if the key exists, otherwise return `-1`.  
> - `void put(int key, int value)` Update the value of the `key` if the `key` exists. Otherwise, add the `key-value` pair to the cache. If the number of keys exceeds the `capacity` from this operation, **evict** the least recently used key.  
> 
> The functions `get` and `put` must each run in `O(1)` average time complexity.  

----------

#### I 哈希表 + 双链表

哈希表可以实现对任意节点的快速定位，双链表便于确定不同 `key-value` 的出现次序并进行调整  

```cpp
struct doubleLinkedList
{
    int key;
    int val;
    doubleLinkedList* prev;
    doubleLinkedList* next;
    doubleLinkedList(): key(0), val(0), prev(nullptr), next(nullptr) {}
    doubleLinkedList(int _key, int _val) : key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache 
{
private:
    unordered_map<int, doubleLinkedList*> cache;
    doubleLinkedList* head;
    doubleLinkedList* tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity): capacity(_capacity), size(0)
    {
        head = new doubleLinkedList;
        tail = new doubleLinkedList;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) 
    {
        if(!cache.count(key))
            return -1;
        moveToHead(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) 
    {
        if(cache.count(key))
        {
            cache[key]->val = value;
            moveToHead(cache[key]);
        }
        else
        {
            doubleLinkedList* cur = new doubleLinkedList(key, value);
            cache[key] = cur;
            addToHead(cur);
            ++size;
            if(size > capacity)
            {
                doubleLinkedList* nodeToDelete = findTail();
                cache.erase(nodeToDelete->key);
                delete nodeToDelete;
                --size;
            }
        }
    }

    void moveToHead(doubleLinkedList* node)
    {
        remove(node);
        addToHead(node);
    }

    void remove(doubleLinkedList* node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }

    void addToHead(doubleLinkedList* node)
    {
        node->next = head->next;
        head->next = node;
        node->prev = head;
        node->next->prev = node;
    }

    doubleLinkedList* findTail()
    {
        doubleLinkedList* cur = tail->prev;
        remove(cur);
        return cur;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
