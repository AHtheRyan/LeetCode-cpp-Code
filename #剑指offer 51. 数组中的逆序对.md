### 数组中的逆序对

> 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。  

----------

#### I 归并排序

可以直接利用归并排序的思想完成逆序数对的求和，对于某一组归并过程，例如 `left == [1, 3, 5]` 和 `right == [2, 4, 6]`：  
由于归并完毕需要进行排序，我们设置 `l` 指针和 `r` 指针分别指向两个数组的最左端，设置 `cnt = 0` 记录总逆序数对的数量  
因为 `left[l] <= right[r]`，所以对 `left[l]` 来说，由于右侧已经完成排序，且右侧最小值比它大，因此不存在逆序数对，将 `l` 指针左移  
此时 `left[l] > right[r]`，所以对 `right[r]` 来说，由于其小于此时的 `left`，由于左侧已经排序完毕，说明 `right[r]` 必然小于 `left` 中的每个数字，逆序数对增加的数目为此时 `left` 剩下的数字数目  
以此类推，可以获得本轮归并过程中的逆序数对的总数  
完成整个个归并过程，即可获得所有的逆序数对  

```cpp
class Solution 
{
private:
    vector<int> tmp;

public:
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        this->tmp.resize(n);
        return div(nums, 0, n - 1);
    }

    int div(vector<int>& nums, int left, int right)
    {
        if(left >= right)
            return 0;
        int mid = left + (right - left) / 2;
        int cnt = div(nums, left, mid) + div(nums, mid + 1, right);
        int i = left;
        int j = mid + 1;
        int index = left;
        while(i <= mid && j <= right)
        {
            if(nums[i] <= nums[j])
                tmp[index++] = nums[i++];
            else
            {
                tmp[index++] = nums[j++];
                cnt += mid - i + 1;
            }
        }
        for(int k = j; k <= right; ++k)
            tmp[index++] = nums[k];
        for(int k = i; k <= mid; ++k)
            tmp[index++] = nums[k];
        copy(tmp.begin() + left, tmp.begin() + right + 1, nums.begin() + left);
        return cnt;
    }
};
```

#### II 去离散化树状数组

此方法的分为两部分：去离散化和树状数组  
1. 去离散化
   - 为了防止数字在 `0 ~ 10^9` 范围内分布过于离散，利用一个将原数组 `nums` 排序的排序树组 `tmp`，确定每个数字在整个数字中的相对大小  
   - 具体过程为：通过自带查找函数在 `tmp` 中找到数字 `num` 的位置，由于 `tmp` 已经排序，所以可以求出其相对于数组开头的距离，此距离可作为相对大小，更新 `nums` 数组中的值  
2. 树状数组
   - 完成去离散化过程后，设置一个数组 `tree` 按顺序记录每个数字在数组中出现的次数，这样，在一个排好序的数组中，对于任意数字 `n` 而言，其逆序数对的数量为 `0 ~ n-1` 中的数字总和  
   - 那对于未排好序的数组而言，可以从右往左遍历 `nums`，每次先判断一个数字 `num` 在 `tree` 中的逆序对总数，再将其更新进 `tree` 中  
   - 这样，遍历到最后，便可以获得总的逆序对的数目  

```cpp
class BIT
{
private:
    int n;
    vector<int> tree;

public:
    BIT(int _n): n(_n), tree(_n + 1) {}

    static int lowbit(int x)
    {
        return x & (-x);
    }

    int query(int x)
    {
        int ret = 0;
        while(x)
        {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void inc(int x)
    {
        while(x <= n)
        {
            ++tree[x];
            x += lowbit(x);
        }
    }

};

class Solution 
{
public:
    int reversePairs(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        for(auto& num : nums)
            num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() + 1;
        BIT bit(n);
        int ret = 0;
        for(int i = n - 1; i >= 0; --i)
        {
            ret += bit.query(nums[i] - 1);
            bit.inc(nums[i]);
        }
        return ret;
    }
};
```
