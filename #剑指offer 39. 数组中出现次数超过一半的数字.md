### 数组中出现次数超过一半的数字

> 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。  
> 你可以假设数组是非空的，并且给定的数组总是存在多数元素。  

----------

#### I Moore投票法

见[多数元素](./%230169%20Majority%20Element%20多数元素.md)

```cpp
int majorityElement(vector<int>& nums) 
{
  int cur = nums[0];
  int cnt = 1;
  for(auto& num : nums)
  {
      if(cur == num)
          ++cnt;
      else
          --cnt;
      if(cnt == 0)
      {
          cur = num;
          cnt = 1;
      }
  }
  return cur;
}
```
