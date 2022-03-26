### 构建乘积数组

> 给定一个数组 `A[0,1,…,n-1]`，请构建一个数组 `B[0,1,…,n-1]`，其中 `B[i]` 的值是数组 `A` 中除了下标 `i` 以外的元素的积, 即 `B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]`。不能使用除法。  

----------

#### I 前缀积

可以利用两个数组，分别储存数组 `a`，从左往右遍历的到每一位相乘的积和从右往左遍历的到每一位相乘的积  
最后按位遍历，分别乘以左右即可  

```cpp
vector<int> constructArr(vector<int>& a) 
{
  int n = a.size();
  vector<int> left = a;
  vector<int> right = a;
  for(int i = 1; i < n; ++i)
      left[i] *= left[i - 1];
  for(int i = n - 2; i >= 0; --i)
      right[i] *= right[i + 1];
  vector<int> ret(n, 1);
  for(int i = 0; i < n; ++i)
  {
      if(i > 0)
          ret[i] *= left[i - 1];
      if(i < n - 1)
          ret[i] *= right[i + 1];
  }
  return ret;
}
```
