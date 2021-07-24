/*
    according to the question, the first bar cannnot trap any water,
    traverse the array from the left to the right, we can analyse each bar as below:
    1. the bar is taller than the left one, then the position will not trap any water
    2. the bar is shorter than the left one, then the volume of trapped water = trapped water in the left + difference of these two bars
    according to this analysis, we can get a map of trapped water,
    but here is the question:
    under this ciucumstence, the trapped water surface on the right of the highest bar will always be equal to the height of the highest,
    the silution is simple, traverse the array from the right to the left, and we can analyse the real condition of the right hand side,
    the result will be the summary of the minimum volume of each site
*/
/*
    根据题意，处在起始位置的柱子处是不可能有积水的，从左往右看分析每个位置，讨论每个位置能积水的量：
    1. 该位置的柱子比左侧的高，那么该位置必然无积水
    2. 该位置的柱子比左侧的低，那么该位置的积水为 左侧的积水 + 两柱子高的差值
    根据此分析，我们遍历整个数组，可以得到一个积水分布，
    但此处有个问题：在此情况下，最高的柱子右侧的积水始终与最高柱子平行，
    解决方法也很简单：从右往左再遍历一次数组，此时可以将最高柱子右侧的积水情况分析完，
    此时可以将两个积水分布在每个位置的最小值相加，结果就是最大积水量
*/

int trap(vector<int>& height)
{
    if (height.empty())
        return 0;
    int size = height.size();
    vector<int> dpl(size);
    vector<int> dpr(size);
    dpl[0] = 0;
    dpr[size - 1] = 0;
    for (int i = 1; i < size; ++i)
    {
        int delta = height[i - 1] - height[i];
        dpl[i] = dpl[i - 1] + delta > 0 ? dpl[i - 1] + delta : 0;
    }
    for (int j = size - 2; j >= 0; --j)
    {
        int delta = height[j + 1] - height[j];
        dpr[j] = dpr[j + 1] + delta > 0 ? dpr[j + 1] + delta : 0;
    }
    vector<int> rain(size);
    for (int k = 0; k < size; ++k)
        rain[k] = dpl[k] > dpr[k] ? dpr[k] : dpl[k];
    int sum = 0;
    for (auto water : rain)
        sum += water;
    return sum;
}
