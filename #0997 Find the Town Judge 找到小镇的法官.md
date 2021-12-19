### 找到小镇的法官
### Find the Town Judge

> 在一个小镇里，按从 `1` 到 `n` 为 `n` 个人进行编号。传言称，这些人中有一个是小镇上的秘密法官。  
> 如果小镇的法官真的存在，那么：  
> 1. 小镇的法官不相信任何人。  
> 2. 每个人（除了小镇法官外）都信任小镇的法官。  
> 3. 只有一个人同时满足条件 1 和条件 2 。  
> 
> 给定数组 `trust`，该数组由信任对 `trust[i] = [a, b]` 组成，表示编号为 `a` 的人信任编号为 `b` 的人。  
> 如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的编号。否则，返回 `-1`。

> In a town, there are `n` people labeled from `1` to `n`. There is a rumor that one of these people is secretly the town judge.  
> If the town judge exists, then:  
> 1. The town judge trusts nobody.  
> 2. Everybody (except for the town judge) trusts the town judge.  
> 3. There is exactly one person that satisfies properties **1** and **2**.  
> 
> You are given an array `trust` where `trust[i] = [ai, bi]` representing that the person labeled `ai` trusts the person labeled `bi`.  
> Return *the label of the town judge if the town judge exists and can be identified, or return `-1` otherwise*.  

----------

#### I 节点入度计算

根据题意，作为一个法官，满足两个条件：
- 相信他的人数为 `n - 1`
- 他相信的人数为 `0`

因此，可以设计两个数列，分别记录每个人被相信的次数和是否相信其他人，  
最后判断每个人是否符合条件即可

```cpp
int findJudge(int n, vector<vector<int>>& trust) 
{
    vector<bool> o(n, false);
    vector<int> i(n);
    for(auto relation : trust)
    {
        o[relation[0] - 1] = true;
        ++i[relation[1] - 1];
    }
    for(int p = 0; p < n; ++p)
        if(i[p] == n - 1 && !o[p])
            return p + 1;
    return -1;
}
```
