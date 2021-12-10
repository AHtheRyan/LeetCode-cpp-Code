### 电话号码的字母组合
### Letter Combinations of a Phone Number

> 给定一个仅包含数字 `2-9` 的字符串，返回所有它能表示的字母组合。答案可以按 **任意顺序** 返回。
> 给出数字到字母的映射与电话按键相同。注意 1 不对应任何字母。  

> Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.  
> A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.  

----------

#### I 哈希表 + 回溯

显然，字母和数字的对应映射是由哈希表建立的  
而字母的连接则由每个数字的对应字母数确定，例如对于数字组合 `23`，先考虑 `2` 的 `'a'` 和 `3` 中的 `'d'` `'e'` `'f'` 分别配对，再考虑 `'b'` `'c'`，以此类推，  
显然可以采用回溯算法，从 `3` 返回 `2` 进行处理

```cpp
class Solution 
{
public:
    unordered_map<char, string> hash
    {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) 
    {
        if(empty(digits))
            return {};
        vector<string> ret;
        string cur;
        backTrack(digits, ret, 0, cur);
        return ret;
    }

    void backTrack(string& digits, vector<string>& ret, int index, string& cur)
    {
        if(index == digits.size())
        {
            ret.push_back(cur);
            return ;
        }
        for(int i = 0; i < hash[digits[index]].size(); ++i)
        {
            string tmp = cur;
            cur += hash[digits[index]][i];
            backTrack(digits, ret, index + 1, cur);
            cur = tmp;
        }
    }
};
```
