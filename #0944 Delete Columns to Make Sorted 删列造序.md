### 删列造序
### Delete Columns to Make Sorted

> 给你由 `n` 个小写字母字符串组成的数组 `strs`，其中每个字符串长度相等。  
> 这些字符串可以每个一行，排成一个网格。例如，`strs = ["abc", "bce", "cae"]` 可以排列为：
```
abc
bce
cae
```
> 你需要找出并删除**不是按字典序升序排列的**列。在上面的例子（下标从 0 开始）中，列 0（`'a'`, `'b'`, `'c'`）和列 2（`'c'`, `'e'`, `'e'`）都是按升序排列的，而列 1（`'b'`, `'c'`, `'a'`）不是，所以要删除列 1 。  
> 返回你需要删除的列数。  

> You are given an array of `n` strings `strs`, all of the same length.  
> The strings can be arranged such that there is one on each line, making a grid. For example, `strs = ["abc", "bce", "cae"]` can be arranged as:
```
abc
bce
cae
```
> You want to **delete** the columns that are **not sorted lexicographically**. In the above example (0-indexed), columns 0 (`'a'`, `'b'`, `'c'`) and 2 (`'c'`, `'e'`, `'e'`) are sorted while column 1 (`'b'`, `'c'`, `'a'`) is not, so you would delete column 1.  
> Return *the number of columns that you will delete*.  

----------

#### I 遍历

简单遍历

```cpp
int minDeletionSize(vector<string>& strs) 
{
    int ret = 0;
    int n = strs.size();
    int m = strs[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            if(strs[j][i] < strs[j - 1][i])
            {
                ++ret;
                break;
            }
        }
    }
    return ret;
}
```
