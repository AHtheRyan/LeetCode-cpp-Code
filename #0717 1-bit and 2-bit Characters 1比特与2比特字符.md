### 1比特与2比特字符
### 1-bit and 2-bit Characters

> 有两种特殊字符：  
> - 第一种字符可以用一个比特 `0` 来表示  
> - 第二种字符可以用两个比特(`10` 或 `11`)来表示
>   
> 给定一个以 `0` 结尾的二进制数组 `bits`，如果最后一个字符必须是一位字符，则返回 `true`。  

> We have two special characters:  
> The first character can be represented by one bit `0`.  
> The second character can be represented by two bits (`10` or `11`).  
> Given a binary array `bits` that ends with `0`, return `true` if the last character must be a one-bit character.  

----------

#### I 倒序计数

根据题意，如果最后的 `0` 需要单独存在，则需要满足条件为：不考虑此 `0`，剩下的比特也能存在  
又由于 `0` 可以单独存在，所以只需要看最后的 `0` 前面的 `1` 的个数：  
- 如果是偶数，则 `1` 可自行配对，不需要最后的 `0`  
- 如果是奇数，则由于 `1` 不能单独存在，必然剩下一个 `1`，需要与最后的 `0` 配对，此时不成立  

```cpp
bool isOneBitCharacter(vector<int>& bits) 
{
    int cnt;
    for(int i = bits.size() - 2; i >= 0; --i)
    {
        if(bits[i] == 1)
            ++cnt;
        else
            break;
    }
    return cnt % 2 == 0;
}
```
