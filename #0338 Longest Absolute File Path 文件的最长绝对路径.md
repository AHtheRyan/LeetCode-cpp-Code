### 文件的最长绝对路径
### Longest Absolute File Path

> 假设有一个同时存储文件和目录的文件系统。  
> 这里将 `dir` 作为根目录中的唯一目录。`dir` 包含两个子目录 `subdir1` 和 `subdir2`。`subdir1` 包含文件 `file1.ext` 和子目录 `subsubdir1`；`subdir2` 包含子目录 `subsubdir2`，该子目录下包含文件 `file2.ext`。  
> 在文本格式中，如下所示(⟶表示制表符)：  
```
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
```
> 如果是代码表示，上面的文件系统可以写为 `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"`。`'\n'` 和 `'\t'` 分别是换行符和制表符。  
> 文件系统中的每个文件和文件夹都有一个唯一的**绝对路径**，即必须打开才能到达文件/目录所在位置的目录顺序，所有路径用 `'/'` 连接。上面例子中，指向 `file2.ext` 的**绝对路径**是 `"dir/subdir2/subsubdir2/file2.ext"`。每个目录名由字母、数字和/或空格组成，每个文件名遵循 `name.extension` 的格式，其中 `name` 和 `extension` 由字母、数字和/或空格组成。  
> 给定一个以上述格式表示文件系统的字符串 `input`，返回文件系统中*指向**文件**的**最长绝对路径**的长度*。如果系统中没有文件，返回 `0`。  

> Suppose we have a file system that stores both files and directories. An example of one system is represented in the following picture:  
> Here, we have `dir` as the only directory in the root. `dir` contains two subdirectories, `subdir1` and `subdir2`. `subdir1` contains a file `file1.ext` and subdirectory `subsubdir1`. `subdir2` contains a subdirectory `subsubdir2`, which contains a file `file2.ext`.  
> In text form, it looks like this (with ⟶ representing the tab character):  
```
dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext
```
> If we were to write this representation in code, it will look like this: `"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"`. Note that the `'\n'` and `'\t'` are the new-line and tab characters.  
> Every file and directory has a unique **absolute path** in the file system, which is the order of directories that must be opened to reach the file/directory itself, all concatenated by `'/'s`. Using the above example, the **absolute path** to `file2.ext` is `"dir/subdir2/subsubdir2/file2.ext"`. Each directory name consists of letters, digits, and/or spaces. Each file name is of the form `name.extension`, where `name` and `extension` consist of letters, digits, and/or spaces.  
> Given a string `input` representing the file system in the explained format, return *the length of the **longest absolute path** to a **file** in the abstracted file system*. If there is no file in the system, return `0`.  

----------

#### I 栈

将单词分隔，基于 `'\t'` 的数目判断当前文件/目录的层级，再比较长度即可  

```cpp
int lengthLongestPath(string input) 
{
    int ret = 0;
    vector<int> name;
    string cur = "";
    bool flag = false;
    for(int i = 0; i <= input.size(); ++i)
    {
        char c = input[i];
        if(c == '.')
            flag = true;
        if(c == '\n' || i == input.size())
        {
            int curlayer = 0;
            while(cur[curlayer] == '\t')
                ++curlayer;
            while(curlayer < name.size())
                name.pop_back();
            int len = cur.size() - curlayer;
            if(name.size() > 0)
                len += name.back() + 1;
            name.push_back(len);
            if(flag)
            {
                ret = max(ret, name.back());
                flag = false;
            }
            cur = "";
        }
        else
            cur += c;
    }
    return ret;
}
```
