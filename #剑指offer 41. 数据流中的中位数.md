### 数据流中的中位数

> 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。  
> 例如，  
> [2,3,4] 的中位数是 3  
> [2,3] 的中位数是 (2 + 3) / 2 = 2.5  
> 设计一个支持以下两种操作的数据结构：  
> - void addNum(int num) - 从数据流中添加一个整数到数据结构中。  
> - double findMedian() - 返回目前所有元素的中位数。  

----------

#### I 优先队列

利用优先队列解决，可设置一个大顶堆和一个小顶堆，前者存储流中较小的一半数字，后者存储流中较大的一半数字  
每加入新元素，就通过 `push` 和 `pop` 将两个堆的大小制衡，确保两者相等或者只差 `1`，这样最后返回堆顶元素或者和的平均数即可  

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
