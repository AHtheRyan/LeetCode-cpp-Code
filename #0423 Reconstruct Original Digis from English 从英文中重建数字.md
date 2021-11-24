### 从英文中重建数字
### Reconstruct Original Digits from English

> 给你一个字符串 `s`，其中包含字母顺序打乱的用英文单词表示的若干数字（`0-9`）。按 **升序** 返回原始的数字。  

> Given a string `s` containing an out-of-order English representation of digits `0-9`, return *the digits in **ascending** order*.  

----------

#### I 根据字母频次计算

我们不妨先对每个字母表示的英文单词进行单词字母拆分，并计算相关的字母出现的次数，可得到以下表格：  
| 字母 | 在 `1-9` 的数字单词中出现的次数 |
| --- | --- |
| z | 1 |
| e | 9 |
| r | 3 |
| o | 4 |
| n | 4 |
| t | 3 |
| w | 1 |
| h | 2 |
| f | 2 |
| u | 1 |
| i | 4 |
| v | 2 |
| s | 2 |
| x | 1 |
| g | 1 |

显然，如果一个字母只出现了一次，则其对应的数字出现的次数可以由该字母出现的次数进行表示，则可以由此先筛选出 `"zero"` `"two"` `"four"` `"six"` `"eight"` 五个数字单词  
之后 ，可以对将每个单词对应的字母的计数减去在 `0 2 4 6 8` 的单词中出现的次数，此时，`"three" "five" "seven"` 也可以被筛选出来  
以此类推，将每个单词都根据其特征字母或者过滤后的特征字母即可求出  

```cpp
string originalDigits(string s) 
{
    unordered_map<char, int> mp;
    for(auto c : s)
        ++mp[c];
    vector<int> numCnt(10);

    numCnt[0] = mp['z'];
    numCnt[2] = mp['w'];
    numCnt[4] = mp['u'];
    numCnt[6] = mp['x'];
    numCnt[8] = mp['g'];
    numCnt[3] = mp['h'] - numCnt[8];
    numCnt[5] = mp['f'] - numCnt[4];
    numCnt[7] = mp['s'] - numCnt[6];
    numCnt[1] = mp['o'] - numCnt[0] - numCnt[2] - numCnt[4];
    numCnt[9] = mp['i'] - numCnt[5] - numCnt[6] - numCnt[8];

    string ret = "";
    for(int i = 0; i < 10; ++i)
    {
        char c = '0' + i;
        ret += string(numCnt[i], c);
    }
    return ret;
}
```
