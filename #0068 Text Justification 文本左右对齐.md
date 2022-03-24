### 文本对齐
### Text Justification

> 给定一个单词数组 `words` 和一个长度 `maxWidth`，重新排版单词，使其成为每行恰好有 `maxWidth` 个字符，且左右两端对齐的文本。  
> 你应该使用 “**贪心算法**” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 `' '` 填充，使得每行恰好有 *maxWidth* 个字符。  
> 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。  
> 文本的最后一行应为左对齐，且单词之间不插入**额外的**空格。  
> 注意:  
> - 单词是指由非空格字符组成的字符序列。  
> - 每个单词的长度大于 0，小于等于 *maxWidth*。  
> - 输入单词数组 `words` 至少包含一个单词。  

> Given an array of strings `words` and a width `maxWidth`, format the text such that each line has exactly `maxWidth` characters and is fully (left and right) justified.  
> You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly `maxWidth` characters.  
> Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.  
> For the last line of text, it should be left-justified and no extra space is inserted between words.  
> **Note**:  
> - A word is defined as a character sequence consisting of non-space characters only.  
> - Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.  
> - The input array `words` contains at least one word.  

----------

#### I 模拟

按照规则进行模拟即可，有三种不同情况需要考虑：  
1. 最后一行，此时需要每个单词间空一格并在最后把空格补上  
2. 只有一个单词，此时在后面补上空格即可  
3. 单词数量大于 `1`，此时计算每个单词间的空格进行改行的模拟创建  

```cpp
class Solution 
{
private:
    string blank(int n)
    {
        return string(n, ' ');
    }

    string join(vector<string>& words, int left, int right, string sep)
    {
        string ret = words[left];
        for(int i = left + 1; i < right; ++i)
            ret += sep + words[i];
        return ret;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        vector<string> ret;
        int n = words.size();
        int right = 0;
        while(true)
        {
            int left = right;
            int sum = 0;
            while(right < n && sum + words[right].size() + right - left <= maxWidth)
                sum += words[right++].size();
            if(right == n)
            {
                string s = join(words, left, n, " ");
                ret.emplace_back(s + blank(maxWidth - s.size()));
                return ret;
            }
            int wordnum = right - left;
            int space = maxWidth - sum;
            if(wordnum == 1)
                ret.emplace_back(words[left] + blank(space));
            else
            {
                int average = space / (wordnum - 1);
                int mod = space % (wordnum - 1);
                string s1 = join(words, left, left + mod + 1, blank(average + 1));
                string s2 = join(words, left + mod + 1, right, blank(average));
                ret.emplace_back(s1 + blank(average) + s2);
            }
        }
    }
};
```
