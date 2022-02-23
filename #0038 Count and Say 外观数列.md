### 外观数列
### Count and Say

> 给定一个正整数 `n`，输出外观数列的第 `n` 项。  
> 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。  
> 你可以将其视作是由递归公式定义的数字字符串序列：  
> - `countAndSay(1) = "1"`
> - `countAndSay(n)` 是对 `countAndSay(n-1)` 的描述，然后转换成另一个数字字符串。
>  
> 前五项如下：  
> > 1  
> > 11  
> > 21  
> > 1211  
> > 111221  
> >
> > 第一项是数字 1  
> > 描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"  
> > 描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"  
> > 描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"  
> > 描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
> 
> 要**描述**一个数字字符串，首先要将字符串分割为**最小**数量的组，每个组都由连续的最多**相同字符**组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。  

> The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:  
> - `countAndSay(1) = "1"`  
> - `countAndSay(n)` is the way you would "say" the digit string from `countAndSay(n-1)`, which is then converted into a different digit string.  
> 
> To determine how you "say" a digit string, split it into the **minimal** number of groups so that each group is a contiguous section all of the **same character**. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.  

----------

#### I 模拟

从 `1` 开始，按部就班模拟即可

```cpp
string countAndSay(int n) 
{
    string ret = "1";
    int curNum = 1;
    while(curNum < n)
    {
        string cur;
        int left = 0;
        int right = 0;
        while(right < ret.size())
        {
            while(right < ret.size() && ret[left] == ret[right])
                ++right;
            cur += to_string(right - left) + ret[left];
            left = right;
        }
        ret = cur;
        ++curNum;
    }
    return ret;
}
```
