### 设计双端循环队列
### Design Circular Deque

> 设计实现双端队列。  
> 实现 `MyCircularDeque` 类:  
> - `MyCircularDeque(int k)`：构造函数,双端队列最大为 `k`。  
> - `boolean insertFront()`：将一个元素添加到双端队列头部。 如果操作成功返回 `true`，否则返回 `false`。  
> - `boolean insertLast()`：将一个元素添加到双端队列尾部。如果操作成功返回 `true`，否则返回 `false`。  
> - `boolean deleteFront()`：从双端队列头部删除一个元素。 如果操作成功返回 `true`，否则返回 `false`。  
> - `boolean deleteLast()`：从双端队列尾部删除一个元素。如果操作成功返回 true ，否则返回 `false`。  
> - `int getFront()`：从双端队列头部获得一个元素。如果双端队列为空，返回 `-1`。  
> - `int getRear()`：获得双端队列的最后一个元素。 如果双端队列为空，返回 `-1`。  
> - `boolean isEmpty()`：若双端队列为空，则返回 `true`，否则返回 `false`。  
> - `boolean isFull()`：若双端队列满了，则返回 `true`，否则返回 `false`。  

> Design your implementation of the circular double-ended queue (deque).  
> Implement the `MyCircularDeque` class:  
> - `MyCircularDeque(int k)` Initializes the deque with a maximum size of `k`.  
> - `boolean insertFront()` Adds an item at the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.  
> - `boolean insertLast()` Adds an item at the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.  
> - `boolean deleteFront()` Deletes an item from the front of Deque. Returns `true` if the operation is successful, or `false` otherwise.  
> - `boolean deleteLast()` Deletes an item from the rear of Deque. Returns `true` if the operation is successful, or `false` otherwise.  
> - `int getFront()` Returns the front item from the Deque. Returns `-1` if the deque is empty.  
> - `int getRear()` Returns the last item from Deque. Returns `-1` if the deque is empty.  
> - `boolean isEmpty()` Returns `true` if the deque is empty, or `false` otherwise.  
> - `boolean isFull()` Returns `true` if the deque is full, or `false` otherwise.  

----------

#### I 数组 + 双指针

利用数组模拟队列的大小，并使用两个指针分别记录队列的前后入口位置  
出入口的下标可以通过取余获得

```cpp
class MyCircularDeque 
{
private:
    int k;
    vector<int> vec;
    int head;
    int tail;

public:
    MyCircularDeque(int k): k(k), head(1), tail(1)
    {
        vec.resize(k);
    }
    
    bool insertFront(int value) 
    {
        if(isFull())
            return false;
        --head;
        int index = ((head % k) + k) % k;
        vec[index] = value;
        return true;
    }
    
    bool insertLast(int value) 
    {
        if(isFull())
            return false;
        int index = ((tail % k) + k) % k;
        vec[index] = value;
        ++tail;
        return true;
    }
    
    bool deleteFront() 
    {
        if(isEmpty())
            return false;
        ++head;
        return true;
    }
    
    bool deleteLast() 
    {
        if(isEmpty())
            return false;
        --tail;
        return true;
    }
    
    int getFront() 
    {
        if(isEmpty())
            return -1;
        int index = ((head % k) + k) % k;
        return vec[index];
    }
    
    int getRear() 
    {
        if(isEmpty())
            return -1;
        int index = (((tail - 1) % k) + k) % k;
        return vec[index];
    }
    
    bool isEmpty() 
    {
        return head == tail;
    }
    
    bool isFull() 
    {
        return tail - head == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```
