### 文本左右对齐
### Text Justification

> 给定一个单词数组和一个长度 `maxWidth`，重新排版单词，使其成为每行恰好有 `maxWidth` 个字符，且左右两端对齐的文本。  
> 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 `' '` 填充，使得每行恰好有 maxWidth 个字符。  
> 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。  
> 文本的最后一行应为左对齐，且单词之间不插入额外的空格。

> Given an array of strings `words` and a width `maxWidth`, format the text such that each line has exactly `maxWidth` characters and is fully (left and right) justified.  
> You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly `maxWidth` characters.  
> Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.   
> For the last line of text, it should be left-justified and no extra space is inserted between words.

----------

#### I 模拟

根据题意对整个单词数组进行模拟即可，声明一个指针 `ptr`，用于记录遍历到的单词位置：  
1. 遍历单词时将单词记录在当前行的字符串数组 `cur` 中，同时记录目前行的字符串长度 `wordNum` ，循环判断当前行的单词数量：   
 - 如果单词长度 + 最小空格长度 < 行最大宽度 `maxWidth`，则可以进行循环：将当前的字符串数组、字符串长度和最小空格数更新  
 - 如果单词长度 + 最小空格长度 >= 行最大宽度 `maxWidth`，或者当前单词恰好组成一行，则结束循环
2. 创建当前行的字符串 `line`，分三种情况讨论：
 - 非最后一行且该行不止一个单词：平均分配总空格数，如果超出则从左往右额外添加，构建改行  
 - 最后一行：以一个空格为间隔添加单词，最后将空格补齐  
 - 非最后一行且只有一个单词：添加单词，最后将空格补齐
3. 将 `line` 添加到返回数组 `ret` 中  

遍历整个单词数组即可  

```cpp
vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    int wordNum = words.size();
    int ptr = 0;
    vector<string> ret;
    while(ptr < wordNum)
    {
        int cntWord = 0;
        int leastSpace = 0;
        vector<string> cur;
        while(ptr < wordNum && (cntWord == 0 && words[ptr].size() == maxWidth || cntWord + leastSpace + 1 + words[ptr].size() <= maxWidth))
        {
            cntWord += words[ptr].size();
            cur.push_back(words[ptr]);
            ++ptr;
            leastSpace = cur.size() - 1;
        }
        string line = "";
        if(leastSpace != 0 && ptr != wordNum)
        {
            int allSpace = maxWidth - cntWord;
            int spaceDiv = allSpace / leastSpace;
            int extra = allSpace % leastSpace;
            for(int i = 0; i < cur.size(); ++i)
            {
                line += cur[i];
                if(i != cur.size() - 1)
                    if(extra)
                    {
                        line += string(spaceDiv + 1, ' ');
                        --extra;
                    }
                    else
                        line += string(spaceDiv, ' ');
            }
        }
        else if(ptr == wordNum)
        {
            for(int i = 0; i < cur.size(); ++i)
            {
                line += cur[i];
                if(maxWidth > line.size())
                    line += ' ';
            }
            if(maxWidth > line.size())
                line += string(maxWidth - line.size(), ' ');
        }
        else
        {
            line += cur[0];
            line += string(maxWidth - line.size(), ' ');
        }
        ret.push_back(line);
    }
    return ret;
}
```
