### 推多米诺
### Push Dominoes

> `n`张多米诺骨牌排成一行，将每张多米诺骨牌垂直竖立。在开始时，同时把一些多米诺骨牌向左或向右推。  
> 每过一秒，倒向左边的多米诺骨牌会推动其左侧相邻的多米诺骨牌。同样地，倒向右边的多米诺骨牌也会推动竖立在其右侧的相邻多米诺骨牌。  
> 如果一张垂直竖立的多米诺骨牌的两侧同时有多米诺骨牌倒下时，由于受力平衡， 该骨牌仍然保持不变。  
> 就这个问题而言，我们会认为一张正在倒下的多米诺骨牌不会对其它正在倒下或已经倒下的多米诺骨牌施加额外的力。  
> 给你一个字符串 `dominoes` 表示这一行多米诺骨牌的初始状态，其中：  
> - `dominoes[i] = 'L'`，表示第 `i` 张多米诺骨牌被推向左侧，  
> - `dominoes[i] = 'R'`，表示第 `i` 张多米诺骨牌被推向右侧，  
> - `dominoes[i] = '.'`，表示没有推动第 `i` 张多米诺骨牌。  
> 
> 返回表示最终状态的字符串。  

> There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.  
> After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.  
> When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.  
> For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.  
> You are given a string `dominoes` representing the initial state where:  
> - `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,  
> - `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and  
> - `dominoes[i] = '.'`, if the `ith` domino has not been pushed.  
> 
> Return a string representing the final state.  

----------

#### I 两次遍历

对于任何一个竖直状态的多米诺牌而言，其最终朝向取决于两个要素：
1. 其左右两侧是否分别有朝右和朝左倒的牌
2. 两侧倒下的牌向他靠近的速率，亦或者说权重  

因此，我们可以对每一个竖直的牌进行分析，根据其与左右两侧倒下的牌的距离分配权重，  
例如，如果一个牌左侧和右侧都有向其倒下的牌，可以将两张牌的权重分别设置为 `50` 和 `-50`，  
两张牌每靠近该牌一秒，则权重就降低 `1`，这样，两张牌到达该牌的位置时，权重有三种可能：  
1. 大于`0`，说明左侧先到，则该牌向右侧倒  
2. 小于`0`，说明右侧先到，则该牌向左侧倒  
3. 等于`0`，说明同时到，则该牌保持竖直  

为了获得每个位置的牌向左右倒的权重，我们需要两次遍历初始状态，分别从左侧和右侧开始，  
为不同位置的牌分配左右倒向的权重，最后可以根据上述规则确定最终状态  

```cpp
string pushDominoes(string& dominoes) 
{
    int n = dominoes.size();
    vector<int> pushLeft(n);
    pushLeft[0] = dominoes[0] == 'R' ? 100000 : 0;
    vector<int> pushRight(n);
    pushRight[n - 1] = dominoes[n - 1] == 'L' ? -100000 : 0;
    for(int i = 1; i < n; ++i)
    {
        if(dominoes[i] == 'L')
            pushLeft[i] = 0;
        else if(dominoes[i] == 'R')
            pushLeft[i] = 100000;
        else if(pushLeft[i - 1] > 0)
            pushLeft[i] = pushLeft[i - 1] - 1;
    }
    for(int j = n - 2; j >= 0; --j)
    {
        if(dominoes[j] == 'R')
            pushRight[j] = 0;
        else if(dominoes[j] == 'L')
            pushRight[j] = -100000;
        else if(pushRight[j + 1] < 0)
            pushRight[j] = pushRight[j + 1] + 1;
    }
    string ret;
    for(int k = 0; k < n; ++k)
    {
        int cur = pushLeft[k] + pushRight[k];
        if(cur > 0)
            ret += 'R';
        else if(cur < 0)
            ret += 'L';
        else
            ret += dominoes[k];
    }
    return ret;
}
```
