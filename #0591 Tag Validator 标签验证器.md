### 标签验证器
### Tag Validator

> 给定一个表示代码片段的字符串，你需要实现一个验证器来解析这段代码，并返回它是否合法。合法的代码片段需要遵守以下的所有规则：  
> 1. 代码必须被**合法的闭合标签**包围。否则，代码是无效的。  
> 2. **闭合标签**（不一定合法）要严格符合格式：`<TAG_NAME>TAG_CONTENT</TAG_NAME>`。其中，`<TAG_NAME>`是起始标签，`</TAG_NAME>`是结束标签。起始和结束标签中的 `TAG_NAME` 应当相同。当且仅当 `TAG_NAME` 和 `TAG_CONTENT` 都是合法的，闭合标签才是**合法**的。  
> 3. **合法**的 `TAG_NAME` 仅含有**大写字母**，长度在范围 `[1,9]` 之间。否则，该 `TAG_NAME` 是**不合法**的。  
> 4. **合法**的 `TAG_CONTENT` 可以包含其他**合法的闭合标签**，**cdata**（请参考规则7）和任意字符（注意参考规则1）**除了**不匹配的`<`、不匹配的起始和结束标签、不匹配的或带有不合法 `TAG_NAME` 的闭合标签。否则，`TAG_CONTENT` 是**不合法**的。  
> 5. 一个起始标签，如果没有具有相同 TAG_NAME 的结束标签与之匹配，是不合法的。反之亦然。不过，你也需要考虑标签嵌套的问题。  
> 6. 一个`<`，如果你找不到一个后续的`>`与之匹配，是不合法的。并且当你找到一个`<`或`</`时，所有直到下一个`>`的前的字符，都应当被解析为 `TAG_NAME`（不一定合法）。  
> 7. cdata 有如下格式：`<![CDATA[CDATA_CONTENT]]>`。`CDATA_CONTENT` 的范围被定义成 `<![CDATA[` 和后续的第一个 `]]>`之间的字符。  
> 8. `CDATA_CONTENT` 可以包含**任意字符**。cdata 的功能是阻止验证器解析`CDATA_CONTENT`，所以即使其中有一些字符可以被解析为标签（无论合法还是不合法），也应该将它们视为**常规**字符。  

> Given a string representing a code snippet, implement a tag validator to parse the code and return whether it is valid.  
> A code snippet is valid if all the following rules hold:  
> 1. The code must be wrapped in a **valid closed tag**. Otherwise, the code is invalid.  
> 2. A **closed tag** (not necessarily valid) has exactly the following format : `<TAG_NAME>TAG_CONTENT</TAG_NAME>`. Among them, `<TAG_NAME>` is the start tag, and `</TAG_NAME>` is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is **valid** if and only if the TAG_NAME and TAG_CONTENT are valid.  
> 3. A **valid** `TAG_NAME` only contain **upper-case letters**, and has length in range [1,9]. Otherwise, the `TAG_NAME` is **invalid**.  
> 4. A **valid** `TAG_CONTENT` may contain other **valid closed tags**, **cdata** and any characters (see note1) **EXCEPT** unmatched `<`, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the `TAG_CONTENT` is **invalid**.  
> 5. A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.  
> 6. A `<` is unmatched if you cannot find a subsequent `>`. And when you find a `<` or `</`, all the subsequent characters until the next `>` should be parsed as TAG_NAME (not necessarily valid).  
> 7. The cdata has the following format : `<![CDATA[CDATA_CONTENT]]>`. The range of `CDATA_CONTENT` is defined as the characters between `<![CDATA[` and the **first subsequent** `]]>`.  
> 8. `CDATA_CONTENT` may contain **any characters**. The function of cdata is to forbid the validator to parse `CDATA_CONTENT`, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as **regular characters**.  

----------

#### I 模拟 + 栈

利用栈完成 `<` 和 `>` 的匹配，按规则进行模拟即可  

```cpp
bool isValid(string code) 
{
    int n = code.size();
    stack<string> tags;
    int i = 0;
    while(i < n)
    {
        if(code[i] == '<')
        {
            if(i == n - 1)
                return false;
            if(code[i + 1] == '/')
            {
                int j = code.find('>', i);
                if(j == string::npos)
                    return false;
                string tagname = code.substr(i + 2, j - i - 2);
                if(tags.empty() || tags.top() != tagname)
                    return false;
                tags.pop();
                i = j + 1;
                if(tags.empty() && i != n)
                    return false;
            }
            else if(code[i + 1] == '!')
            {
                if(tags.empty())
                    return false;
                string cdata = code.substr(i + 2, 7);
                if(cdata != "[CDATA[")
                    return false;
                int j = code.find("]]>", i);
                if(j == string::npos)
                    return false;
                i = j + 1;
            }
            else
            {
                int j = code.find('>', i);
                if(j == string::npos)
                    return false;
                string tagname = code.substr(i + 1, j - i - 1);
                if(tagname.size() < 1 || tagname.size() > 9)
                    return false;
                if(!all_of(tagname.begin(), tagname.end(), [](char& c){return isupper(c);}))
                    return false;
                tags.push(move(tagname));
                i = j + 1;
            }
        }
        else
        {
            if(tags.empty())
                return false;
            ++i;
        }
    }
    return tags.empty();
}
```
