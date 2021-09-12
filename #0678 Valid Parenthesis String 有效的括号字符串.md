### 有效的括号字符串
### Valid Parenthesis String

> 给定一个只包含三种字符的字符串：`（` ，`）` 和 `*`，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：  
> 任何左括号 `(` 必须有相应的右括号 `)`。  
> 任何右括号 `)` 必须有相应的左括号 `(` 。  
> 左括号 `(` 必须在对应的右括号之前 `)`。  
> `*` 可以被视为单个右括号 `)` ，或单个左括号 `(` ，或一个空字符串。  
> 一个空字符串也被视为有效字符串。  

> Given a string `s` containing only three types of characters: `(`, `)` and `*`, return `true` if `s` is **valid**.  
> The following rules define a **valid** string:  
> Any left parenthesis `(` must have a corresponding right parenthesis `)`.  
> Any right parenthesis `)` must have a corresponding left parenthesis `(`.  
> Left parenthesis `(` must go before the corresponding right parenthesis `)`.  
> `*` could be treated as a single right parenthesis `)` or a single left parenthesis `(` or an empty string `""`.

----------

#### I 基于栈的括号匹配

基本的括号匹配（即 `(` 和 `)`）可以直接利用栈进行快速判断，  
对于新增加的 `*`，由于其可以作为 `(` 、 `)` 和 `""`，所以可以作为一种特殊情况，另外设置一个栈来处理，  
这里，我们设置两个栈 `stk` 和 `stks` 分别记录 `(` 和 `*` 的字符串下标位置，同时开始遍历整个字符串：  
1. 如果遇到的字符为 `(` 或 `*`，则将其下标分别放入两个栈中  
2. 如果遇到的字符为 `)`：
   - 如果两个栈都为空，则说明 `)` 无法匹配，则直接返回 `false`
   - 否则，如果 `stk` 栈不为空，则可以使用一个 `(` 与当前字符进行匹配，将其出栈
   - 否则，如果 `stks` 栈不为空，则可以使用一个 `*` 与当前字符进行匹配，将其出栈  
   - **注意**：经验证，这里的 `*` 和 `(` 出现的顺序不会影响匹配结果，可以以上述顺序进行匹配  

按照上述操作预处理完两个栈后，可以进行 `(` 与 `*` 的匹配判断，显然，此处最重要的点是两者出现的顺序：  
依次比较两个栈顶的下标，如果 `*` 在 `(` 之后，则可以实现匹配，否则会出现单独的 `(`，则直接返回 `false`  
最后，如果 `stk` 为空栈，则显然可以满足条件，返回 `true`  

```cpp
bool checkValidString(string s) 
{
    stack<int> stk;
    stack<int> stks;
    for(int i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if(c == '(')
            stk.push(i);
        else if(c == '*')
            stks.push(i);
        else
        {
            if(stk.empty() && stks.empty())
                return false;
            else if(!stk.empty())
                stk.pop();
            else
                stks.pop();
        }
    }
    while(!stk.empty() && !stks.empty())
    {
        if(stks.top() > stk.top())
        {
            stk.pop();
            stks.pop();
        }
        else
            return false;
    }
    return stk.empty();
}
```

#### II 基于贪心算法的括号匹配

根据上面的分析我们可以看到：  
1. 如果出现的字符为 `(`，那么必然需要入栈 
2. 如果出现的字符为 `)`，那么必然需要出栈
3. 如果出现的字符为 `*`，那么分情况讨论，其可能作为 `(`、`)`、`*` 的任意一种  

那么，以上面的三种情况进行讨论，分析 `(` 的数目 `num` 的变化可以发现：
1. `num = num + 1`
2. `num = num - 1`
3. `num = num + 1 | num - 1 | num`  

即 `num` 存在最大 `num_max` 和最小 `num_min` 两种情况，且：  
1. 只要当前为 `(`，则最大最小值都 + 1
2. 只要当前为 `)`，则最大最小值都 - 1
3. 只要当前为 `*`，则最大值 + 1，最小值 - 1
- 而限制条件为：
  - 最大值如果小于 0，则说明存在 `)` 不能实现匹配，直接返回 `false`
  - 最小值不能小于 0，因为考虑 `*` 的存在时不会故意将其看做 `)` 导致适配  

按照上述条件进行遍历，如果最后最小值为 0，则说明在考虑 `*` 的情况下，实现了所有括号的匹配，则可以返回 `true`，否则返回 `false`  

```cpp
bool checkValidString(string s) 
{
    int min = 0;
    int max = 0;
    for(char c : s)
    {
        max = c == ')' ? max - 1 : max + 1;
        min = c != '(' ? (min == 0 ? 0 : min - 1) : ++min; 
        if(max < 0)
            return false;
    }
    return min == 0;
}
```
