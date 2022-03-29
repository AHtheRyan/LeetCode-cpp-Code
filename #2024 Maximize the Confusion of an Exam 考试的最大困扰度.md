### 考试的最大困扰度
### Maximize the Confusion of an Exam

> 一位老师正在出一场由 `n` 道判断题构成的考试，每道题的答案为 true （用 `'T'` 表示）或者 false （用 `'F'` 表示）。老师想增加学生对自己做出答案的不确定性，方法是**最大化**有**连续相同**结果的题数。（也就是连续出现 true 或者连续出现 false）。  
> 给你一个字符串 `answerKey`，其中 `answerKey[i]` 是第 `i` 个问题的正确结果。除此以外，还给你一个整数 `k`，表示你能进行以下操作的最多次数：  
> - 每次操作中，将问题的正确答案改为 `'T'` 或者 `'F'`（也就是将 `answerKey[i]` 改为 `'T'` 或者 `'F'`）。  
> 
> 请你返回在不超过 `k` 次操作的情况下，最大 连续 `'T'` 或者 `'F'` 的数目。  

> A teacher is writing a test with `n` true/false questions, with `'T'` denoting true and `'F'` denoting false. He wants to confuse the students by **maximizing** the number of **consecutive** questions with the **same** answer (multiple trues or multiple falses in a row).  
> You are given a string `answerKey`, where `answerKey[i]` is the original answer to the `ith` question. In addition, you are given an integer `k`, the maximum number of times you may perform the following operation:  
> - Change the answer key for any question to `'T'` or `'F'` (i.e., set `answerKey[i]` to `'T'` or `'F'`).  
> 
> Return *the **maximum** number of consecutive `'T'`s or `'F'`s in the answer key after performing the operation at most `k` times*.  

----------

#### I 滑动窗口

此题类似于[无重复字符的最长子串](./%230003%20Longest%20Substring%20Without%20Repeating%20Characters%20无重复字符的最长子串.md)，可通过滑动窗口进行解答  
分别确定 `'T'` 和 `'F'` 两个单词的出现次数，并对另一种答案进行更改，假设对 `'T'` 进行最长的判断：  
1. 设置双指针 `left` 和 `right`，分别指向满足条件的最左侧答案位置和最右侧答案位置  
2. 先将 `right` 指针右移，直到出现 `'F'` 的次数刚好为 `k` 次，记录下此时的长度  
3. 将 `right` 指针继续右移，直到再出现一次 `'F'`，此时可以移动 `left` 指针，直到其停在第一个遇到的 `F` 的右侧  
4. 重复上述 `2` 和 `3`，每次都记录长度，并与记录长度进行比较  
5. 返回最长的长度即可  

```cpp
class Solution 
{
public:
    int maxConsecutiveAnswers(string answerKey, int k) 
    {
        return max(change(answerKey, k, 'T'), change(answerKey, k, 'F'));
    }

    int change(string& s, int& k, const char& c)
    {
        int n = s.size();
        int ret = 0;
        for(int left = 0, right = 0, sum = 0; right < n; ++right)
        {
            if(s[right] != c)
                ++sum;
            while(sum > k)
                if(s[left++] != c)
                    --sum;
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
```
