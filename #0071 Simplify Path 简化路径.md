### 简化路径
### Simplify Path

> 给你一个字符串 `path`，表示指向某一文件或目录的 Unix 风格**绝对路径**（以 `'/'` 开头），请你将其转化为更加简洁的规范路径。  
> 在 Unix 风格的文件系统中，一个点（`.`）表示当前目录本身；此外，两个点 （`..`） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。任意多个连续的斜杠（即，`'//'`）都被视为单个斜杠 `'/'`。 对于此问题，任何其他格式的点（例如，'`...`'）均被视为文件/目录名称。  
> 请注意，返回的**规范路径**必须遵循下述格式：  
> - 始终以斜杠 `'/'` 开头。  
> - 两个目录名之间必须只有一个斜杠 `'/'`。  
> - 最后一个目录名（如果存在）**不能**以 `'/'` 结尾。  
> - 此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 `'.'` 或 `'..'`）。  
> 
> 返回简化后得到的**规范路径**。  

> Given a string `path`, which is an **absolute path** (starting with a slash `'/'`) to a file or directory in a Unix-style file system, convert it to the simplified **canonical path**.  
> In a Unix-style file system, a period `'.'` refers to the current directory, a double period `'..'` refers to the directory up a level, and any multiple consecutive slashes (i.e. `'//'`) are treated as a single slash `'/'`. For this problem, any other format of periods such as `'...'` are treated as file/directory names.  
> The **canonical path** should have the following format:  
> - The path starts with a single slash `'/'`.  
> - Any two directories are separated by a single slash `'/'`.  
> - The path does not end with a trailing `'/'`.  
> - The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period `'.'` or double period `'..'`)  
> 
> Return *the simplified **canonical path***.  

----------

#### I 双端队列模拟

将原字符串按照 `/` 为分界线进行分割，  
再按照简化规则，对 `"."` 和 `".."` 分别进行讨论即可  

```cpp
class Solution 
{
public:
    string simplifyPath(string path) 
    {
        vector<string> part = split(path);
        deque<string> q;
        string ret;
        for(auto& str: part)
        {
            if(str == "." || str == ".." && q.empty())
                continue;
            else if(str == ".." && !q.empty())
                q.pop_back();
            else
                q.push_back(str);
        }
        while(!q.empty())
        {
            ret += '/' + q.front();
            q.pop_front();
        }
        return ret == "" ? "/" : ret;
    }

    vector<string> split(string& path)
    {
        vector<string> ret;
        string cur = "";
        for(int i = 1; i < path.size(); ++i)
        {
            if(path[i] == '/' && cur != "")
            {
                ret.emplace_back(cur);
                cur = "";
            }
            else if(path[i] != '/')
                cur += path[i];
        }
        if(cur != "")
            ret.emplace_back(cur);
        return ret;
    }
};
```
