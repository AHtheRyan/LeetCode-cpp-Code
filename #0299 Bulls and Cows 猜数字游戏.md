### 猜数字游戏
### Bulls and Cows

> 你在和朋友一起玩 **猜数字（Bulls and Cows）** 游戏，该游戏规则如下：  
> 写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：  
> - 猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls", 公牛），  
> - 有多少位属于数字猜对了但是位置不对（称为 "Cows", 奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。  
> 
> 给你一个秘密数字 `secret` 和朋友猜测的数字 `guess`，请你返回对朋友这次猜测的提示。  
> 提示的格式为 `"xAyB"`，`x` 是公牛个数， `y` 是奶牛个数，`A` 表示公牛，`B` 表示奶牛。  
> 请注意秘密数字和朋友猜测的数字都可能含有重复数字。  

> You are playing the **Bulls and Cows** game with your friend.  
> You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:  
> - The number of "bulls", which are digits in the guess that are in the correct position.  
> - The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.  
> 
> Given the secret number `secret` and your friend's guess `guess`, return *the hint for your friend's guess*.  
> The hint should be formatted as `"xAyB"`, where `x` is the number of bulls and `y` is the number of cows. Note that both `secret` and `guess` may contain duplicate digits.  

----------

#### I 模拟

遍历两个数组，按位置比较每个数字即可得到准确数字的确切出现次数，  
再针对两个数组计数并进行每个数字出现次数的插值计算，即可获得位置不对数字的确切出现次数

```cpp
string getHint(string secret, string guess) 
{
    vector<int> cnt_secret(10);
    vector<int> cnt_guess(10);
    int bulls = 0;
    int cows = 0;
    for(int i = 0; i < secret.size() && i < guess.size(); ++i)
    {
        if(secret[i] == guess[i])
            ++bulls;
        else
        {
            ++(cnt_secret[secret[i] - '0']);
            ++(cnt_guess[guess[i] - '0']);
        }
    }
    for(int i = 0; i < 10; ++i)
        cows += min(cnt_guess[i], cnt_secret[i]);
    string ret = "";
    ret += to_string(bulls) + 'A' + to_string(cows) + 'B';
    return ret;
}
```
