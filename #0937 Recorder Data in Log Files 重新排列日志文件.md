### 重新排列日志文件
### Recorder Data in Log Files

> 给你一个日志数组 `logs`。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的**标识符**。  
> 有两种不同类型的日志：  
> - **字母日志**：除标识符之外，所有字均由小写字母组成  
> - **数字日志**：除标识符之外，所有字均由数字组成  
> 
> 请按下述规则将日志重新排序：  
> - 所有**字母日志**都排在**数字日志**之前。  
> - **字母日志**在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。  
> - **数字日志**应该保留原来的相对顺序。  
> 
> 返回日志的最终顺序。  

> You are given an array of `logs`. Each log is a space-delimited string of words, where the first word is the **identifier**.  
> There are two types of logs:  
> - **Letter-logs**: All words (except the identifier) consist of lowercase English letters.  
> - **Digit-logs**: All words (except the identifier) consist of digits.  
> 
> Reorder these logs so that:  
> 1. The **letter-logs** come before all **digit-logs**.  
> 2. The **letter-logs** are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.  
> 3. The **digit-logs** maintain their relative ordering.  
> 
> Return *the final order of the logs*.  

----------

#### I lambda表达式排序

利用 `stable_sort` 可以基于lambda表达式快速完成整体的排序过程  

```cpp
vector<string> reorderLogFiles(vector<string>& logs) 
{
    stable_sort(logs.begin(), logs.end(), [&](const string& a, const string &b){
        int pos1 = a.find_first_of(" ");
        int pos2 = b.find_first_of(" ");
        bool isDigit1 = isdigit(a[pos1 + 1]);
        bool isDigit2 = isdigit(b[pos2 + 1]);
        if(isDigit1 && isDigit2)
            return false;
        if(!isDigit1 && ! isDigit2)
        {
            string s1 = a.substr(pos1);
            string s2 = b.substr(pos2);
            if(s1 == s2)
                return a < b;
            else
                return s1 < s2;
        }
        return isDigit1 ? false : true;
    });
    return logs;
}
```
