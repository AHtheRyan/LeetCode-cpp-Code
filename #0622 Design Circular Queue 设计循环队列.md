### 设计循环队列
### Design Circular Queue

> 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。  
> 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。  
> 你的实现应该支持如下操作：  
> - `MyCircularQueue(k)`: 构造器，设置队列长度为 k。  
> - `Front`: 从队首获取元素。如果队列为空，返回 -1。  
> - `Rear`: 获取队尾元素。如果队列为空，返回 -1。  
> - `enQueue(value)`: 向循环队列插入一个元素。如果成功插入则返回真。  
> - `deQueue()`: 从循环队列中删除一个元素。如果成功删除则返回真。  
> - `isEmpty()`: 检查循环队列是否为空。  
> - `isFull()`: 检查循环队列是否已满。  

> Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".  
> One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.  
> Implementation the `MyCircularQueue` class:  
> - `MyCircularQueue(k)` Initializes the object with the size of the queue to be `k`.  
> - `int Front()` Gets the front item from the queue. If the queue is empty, return `-1`.  
> - `int Rear()` Gets the last item from the queue. If the queue is empty, return `-1`.  
> - `boolean enQueue(int value)` Inserts an element into the circular queue. Return `true` if the operation is successful.  
> - `boolean deQueue()` Deletes an element from the circular queue. Return `true` if the operation is successful.  
> - `boolean isEmpty()` Checks whether the circular queue is empty or not.  
> - `boolean isFull()` Checks whether the circular queue is full or not.  
> 
> You must solve the problem without using the built-in queue data structure in your programming language.   

----------

#### I 数组

利用数组实现确定大小的队列  
队列的前后出入口可以通过数组下标确定，只要保证**出口下标 - 入口下标 <= 队列大小**即可  
此外，出入口的实际下标可以通过取余来获得  

```cpp
class MyCircularQueue 
{
private:
    int capacity;
    int findex, tindex;
    vector<int> cq;

public:
    MyCircularQueue(int k): capacity(k), findex(0), tindex(0)
    {
        cq.resize(k);
    }
    
    bool enQueue(int value) 
    {
        if(tindex - findex == capacity)
            return false;
        int index = tindex % capacity;
        cq[index] = value;
        ++tindex;
        return true;
    }
    
    bool deQueue() 
    {
        if(tindex == findex)
            return false;
        ++findex;
        return true;
    }
    
    int Front() 
    {
        if(findex == tindex)
            return -1;
        return cq[findex % capacity];
    }
    
    int Rear() 
    {
        if(findex == tindex)
            return -1;
        return cq[(tindex - 1) % capacity];
    }
    
    bool isEmpty() 
    {
        return tindex == findex;
    }
    
    bool isFull() 
    {
        return (tindex - findex) == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```
