### 字符串中的单词数
### Number of Segments in a String

> 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。  
> 请注意，你可以假定字符串里不包括任何不可打印的字符。  

> You are given a string `s`, return *the number of segments in the string*.   
> A **segment** is defined to be a contiguous sequence of **non-space characters**.  

----------

#### I 遍历判断

遍历字符串，以单词为单位进行计数即可  
这里我们设置两个变量，一个记录非空格的数目 `count`，一个记录单词数目 `ret`，规则如下；  
- 如果不是空格，则 `count` 递增  
- 如果是空格，且 `count` 不是 `0`，则 `ret` 递增，并将 `count` 归零  

考虑最后为单词的情况，判断最后一个字符是否不为 `' '`，如果是，则 `ret` 递增，否则不变  
最后返回单词计数器 `ret` 即可

```cpp
int countSegments(string s) 
{
    int count = 0;
    int ret = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] != ' ')
            ++count;
        else if(s[i] == ' ' && count)
        {
            ++ret;
            count = 0;
        }
    }
    if(count && s[s.size() - 1] != ' ')
        ++ret;
    return ret;
}
````
