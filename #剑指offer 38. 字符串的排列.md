### 字符串的排列

> 输入一个字符串，打印出该字符串中字符的所有排列。  
> 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。  

----------

#### I 回溯

回溯可以解决排列问题  
为了去重，我们在代码中做如下考虑：  
当针对某个位置 `i` 的元素进行对换调整时，我们从起点 `index` 处进行遍历，依次确认每个位置的元素是否与 `s[i]` 相同：  
- 如果相同，说明此字符已经用作对换了，不再进行相同操作  
- 如果不同，说明次字符第一次出现，可以进行操作  

按上述方案进行剪枝，最后依次输出排列结果即可  

```cpp
class Solution 
{
private:
    vector<string> ret;

public:
    vector<string> permutation(string s) 
    {
        backtrack(s, 0);
        return ret;
    }

    void backtrack(string& s, int index)
    {
        if(index == s.size())
            ret.push_back(s);
        for(int i = index; i < s.size(); ++i)
        {
            bool flag = true;
            for(int j = index; j < i; ++j)
                if(s[j] == s[i])
                    flag = false;
            if(flag)
            {
                swap(s[index], s[i]);
                backtrack(s, index + 1);
                swap(s[index], s[i]);
            }
        }
    }
};
```
