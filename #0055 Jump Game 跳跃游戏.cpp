/*
    every number in the array represents distance we can move forward, and we will consume 1 value(seen as energy) as we move 1 step forward according to the rule,
    E.G. in array[2, 3, 1, 1, 4], we will consume 1 energy from "2" to "3".
    considering moving to the first "1":
    1. move from "2" to "1", which means consuming 1 energies and obtaining 1 energy
    2. firstly move from "2" to "3", them from "3" to "1", which means consuming 1 energy and meanwhile getting the chance of moving forward continuously to find the maximum number of energy we can get,
    in other words, we can consider our move as how many energies we can get by the time we get to every position until we use up our energy or get to the end,
    so, we can create a dp array to record the highest energies we can get on each position, which obtained from the maximum between "passed by energy" and "stop energy",
    if we cannot pass by a certain position, which means no energy left in the previous position, return false, or we return true
*/
/*
    数组中每个位置代表当前位置可以前进的距离，根据规则，每前进一格，就会消耗一个值（我们可以看做能量），例如，在数组[2, 3, 1, 1, 4]中，从 “2” 前进到 “3”，则消耗1点“能量”。
    考虑前进到第一个数字 “1”：
    1. 从 “2” 前进到第一个 “1”，则消耗2点“能量”，到 “1” 可重新获得1点能量，
    2. 先从 “2” 到 “3”， 再从 “3” 再到 “1”，此时消耗1点能量，但可以继续前进不停留，试图获得更多能量，直到找到能量最高的位置停下来，
    也就是说，最终考虑的就是按顺序到达每个位置可以获得的最大能量是多少，直到没有能量或者到终点，
    因此，可以构建dp数组，记录每个位置的能量最大值，考虑情况1和2，能量值为前一格直接前进的能量（即路过不停留）和当前格子的能量（停在此格获得能量）两者的较大者，
    如果根本无法路过，也就是前一格的剩余能量为0，则直接无法前进，返回false，否则遍历到最后，返回true
*/

//v1.0
bool canJump(vector<int>& nums)
{
    int size = nums.size();
    vector<int> dp(size);
    dp[0] = nums[0];
    for (int i = 1; i < size; ++i)
    {
        int pre = dp[i - 1] - 1;
        if (pre < 0)
            return false;
        dp[i] = pre > nums[i] ? pre : nums[i];
    }
    return true;
}

//v1.1
//use variable named "rightmost" to record the highest energy in every position
//在前面的基础上做了修改，使用一个变量rightmost记录每个格子可以前进的最大值
bool canJump(vector<int>& nums)
{
    int n = nums.size();
    int rightmost = 0;
    for (int i = 0; i < n; ++i)
    {
        if (i <= rightmost)
        {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost >= n - 1)
                return true;
        }
    }
    return false;

