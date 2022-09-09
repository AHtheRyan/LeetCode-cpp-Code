### 文件夹操作日志收集器
### Crawler Log Folder

> 每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。  
> 下面给出对变更操作的说明：  
> - `"../"` ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则**继续停留在当前文件夹**。  
> - `"./"` ：继续停留在当前文件夹。  
> - `"x/"` ：移动到名为 `x` 的子文件夹中。题目数据**保证总是存在文件夹 `x`**。  
> 
> 给你一个字符串列表 `logs`，其中 `logs[i]` 是用户在 `ith` 步执行的操作。  
> 文件系统启动时位于主文件夹，然后执行 `logs` 中的操作。  
> 执行完所有变更文件夹操作后，请你找出**返回主文件夹所需的最小步数**。  

> The Leetcode file system keeps a log each time some user performs a change folder operation.  
> The operations are described below:  
> - `"../"` : Move to the parent folder of the current folder. (If you are already in the main folder, **remain in the same folder**).  
> - `"./"` : Remain in the same folder.  
> - `"x/"` : Move to the child folder named x (This folder is **guaranteed to always exist**).  
> 
> You are given a list of strings `logs` where `logs[i]` is the operation performed by the user at the `ith` step.  
> The file system starts in the main folder, then the operations in `logs` are performed.  
> Return *the minimum number of operations needed to go back to the main folder after the change folder operations*.  

----------

#### I 简单模拟

按照文件路径规则进行模拟即可  

```cpp
int minOperations(vector<string>& logs) 
{
    int step = 0;
    for(auto& log : logs)
    {
        if(log == "./")
            continue;
        else if(log == "../")
            step = step == 0 ? 0 : step - 1;
        else
            ++step;
    }
    return step;
}
```
