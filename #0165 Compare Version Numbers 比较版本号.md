### 比较版本号
### Compare Version Numbers

> 给你两个版本号 `version1` 和 `version2` ，请你比较它们。  
> 版本号由一个或多个修订号组成，各修订号由一个 `'.'` 连接。每个修订号由 多位数字 组成，可能包含 前导零 。每个版本号至少包含一个字符。修订号从左到右编号，下标从 0 开始，最左边的修订号下标为 0 ，下一个修订号下标为 1 ，以此类推。例如，`2.5.33` 和 `0.1` 都是有效的版本号。  
> 比较版本号时，请按从左到右的顺序依次比较它们的修订号。比较修订号时，只需比较 忽略任何前导零后的整数值 。也就是说，修订号 `1` 和修订号 `001` 相等 。如果版本号没有指定某个下标处的修订号，则该修订号视为 `0` 。例如，版本 `1.0` 小于版本 `1.1` ，因为它们下标为 `0` 的修订号相同，而下标为 `1` 的修订号分别为 `0` 和 `1` ，`0 < 1` 。  
> 返回规则如下：
> - 如果 `version1 > version2` 返回 `1`，
> - 如果 `version1 < version2` 返回 `-1`，
> - 除此之外返回 `0`。  

> Given two version numbers, `version1` and `version2`, compare them.  
> Version numbers consist of **one or more revisions** joined by a dot `'.'`. Each revision consists of **digits** and may contain leading **zeros**. Every revision contains **at least one character**. Revisions are **0-indexed from left to right**, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example `2.5.33` and `0.1` are valid version numbers.  
> To compare version numbers, compare their revisions in **left-to-right order**. Revisions are compared using their **integer value ignoring any leading zeros**. This means that revisions `1` and `001` are considered **equal**. If a version number does not specify a revision at an index, then **treat the revision as `0`**. For example, version `1.0` is less than version `1.1` because their revision 0s are the same, but their revision 1s are `0` and `1` respectively, and `0 < 1`.  
> Return the following:  
> - If `version1 < version2`, return `-1`.  
> - If `version1 > version2`, return `1`.  
> - Otherwise, return `0`.  

----------

#### I 双指针

题目本身难度不大，重点在于将字符串以 `'.'` 为单位进行分割比较模拟即可  
因为比较两个字符串，所以采用双指针解决，对于长度不等的字符串，处理方式类似于 [#0002 Add Two Numbers 两数相加](./%230002%20Add%20Two%20Numbers%20两数相加.md)  

```cpp
int compareVersion(string version1, string version2) 
{
    int len1 = version1.size();
    int len2 = version2.size();
    int ptr1 = 0;
    int ptr2 = 0;
    while(ptr1 < len1 || ptr2 < len2)
    {
        int cmp1 = 0;
        int cmp2 = 0;
        if(ptr1 < len1)
            while(ptr1 < len1 && version1[ptr1] != '.')
                cmp1 = cmp1 * 10 + version1[ptr1++] - '0';
        ++ptr1;
        if(ptr2 < len2)
            while(ptr2 < len2 && version2[ptr2] != '.')
                cmp2 = cmp2 * 10 + version2[ptr2++] - '0';
        ++ptr2;
        if(cmp1 > cmp2)
            return 1;
        else if(cmp1 < cmp2)
            return -1;
    }
    return 0;
}
```
