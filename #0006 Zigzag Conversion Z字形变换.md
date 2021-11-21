### Z字形变换
### Zigzag Conversion

> 将一个给定字符串 `s` 根据给定的行数 `numRows`，以从上往下、从左到右进行 Z 字形排列。  
> 比如输入字符串为 `"PAYPALISHIRING"` 行数为 `3` 时，排列如下：  
> `P___A___H___N`  
> `A_P_L_S_I_I_G`  
> `Y___I___R`  
> 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如：`"PAHNAPLSIIGYIR"`。  

> The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)  
> `P___A___H___N`  
> `A_P_L_S_I_I_G`  
> `Y___I___R`  
> And then read line by line: `"PAHNAPLSIIGYIR"`  

----------

#### I 模拟

利用Z字变换的性质，通过数组分别记录每行的字母，  
利用标志位 `down` 记录当前按行排列的上下移动状态，利用行记录位 `rowMark` 记录当前遍历到的行，根据是否到达第一行或最后一行进行改变    
最后把各行的字符串拼接在一块即可  

```cpp
string convert(string s, int numRows) 
{
    int size = s.size();
    vector<string> line(size);
    int count = 0;
    int rowMark = 0;
    bool down = false;
    while(count < size)
    {
        if(rowMark == 0 || rowMark == numRows - 1)
            down = !down;
        line[rowMark] += s[count++];
        rowMark = down ? rowMark + 1 : rowMark - 1;
    }
    string ret = "";
    for(auto str : line)
        ret += str;
    return ret;
}
```
