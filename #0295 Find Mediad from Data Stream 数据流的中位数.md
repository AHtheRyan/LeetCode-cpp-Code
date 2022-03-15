### 数据流的中位数
### Find Median from Data Stream

> 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。  
> 例如，  
> [2,3,4] 的中位数是 3  
> [2,3] 的中位数是 (2 + 3) / 2 = 2.5  
> 设计一个支持以下两种操作的数据结构：  
> - void addNum(int num) - 从数据流中添加一个整数到数据结构中。  
> - double findMedian() - 返回目前所有元素的中位数。  

> The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.  
> - For example, for `arr = [2,3,4]`, the median is `3`.  
> - For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.  
> 
> Implement the MedianFinder class:  
> - `MedianFinder()` initializes the `MedianFinder` object.  
> - `void addNum(int num)` adds the integer `num` from the data stream to the data structure.  
> - `double findMedian()` returns the median of all elements so far. Answers within `10^-5` of the actual answer will be accepted.  

----------

#### I 优先队列

见[数据流的中位数](./%23剑指offer%2041.%20数据流中的中位数.md)  

```cpp
class MedianFinder 
{
private:
    priority_queue<int, vector<int>, less<int>> bigTop;         //小的一半
    priority_queue<int, vector<int>, greater<int>> smallTop;    //大的一半

public:
    /** initialize your data structure here. */
    MedianFinder() 
    {}
    
    void addNum(int num) 
    {
        if(bigTop.empty() || num < bigTop.top())
        {
            bigTop.push(num);
            if(smallTop.size() + 1 < bigTop.size())
            {
                smallTop.push(bigTop.top());
                bigTop.pop();
            }
        }
        else
        {
            smallTop.push(num);
            if(smallTop.size() > bigTop.size())
            {
                bigTop.push(smallTop.top());
                smallTop.pop();
            }
        }
    }
    
    double findMedian() 
    {
        if(bigTop.size() > smallTop.size())
            return double(bigTop.top());
        return double(bigTop.top() + smallTop.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```
