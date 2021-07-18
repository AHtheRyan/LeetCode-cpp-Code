/*
    every scores gotten from the numbers will be affected by two factors: the number itself and the times the number appears,
    E.G. in array [2, 2, 3, 3, 3, 4], choose number "3" actually means getting every "3" in the array,
    which means we can transfer the array into another form: [(2, 2), (3, 3), (4, 1)], in which the 1st number means the number itself, and the 2nd number means the times the number appears,
    and the multipication of the pair shows a number's real value,
    we can further transfer it into[4, 9, 4], where the three numbers correspond to the  numbers 2, 3, 4,
    after each value is chosen, the adjacent value is deleted directly, so we can convert it into two corresponding arrays:
    [0, 1, 2, 3, 4] which represents the number itself,
    [0, 0, 4, 9, 4] which represents the scores we can get after choose the number,
    according to the rules, if we choose a certain number, we cannot choose the numbers before and after it,
    thus the question can be transformed into the "#198 House Robber" problem, which can be solved by dynamic programming.
*/
/*
    ÿһ��������صķ���������������Ӱ�죺���ֵ�ֵ�͸����ֳ��ֵĴ�����
    ������[2, 2, 3, 3, 3, 4]�У�ѡ�� ��3�� ʵ���Ͼ��ǰ�ÿ��3����ã�
    ��Ҳ����ζ�ţ�������ʵ���Ͽ��Կ��������Ķ�Ԫ���飺[(2, 2), (3, 3), (4, 1)]��ÿһ������ǰ�ߴ������ֵ�ֵ�����ߴ������ֳ��ֵĴ���������ʵ���������ļ�ֵ��������ˣ�
    ��һ��ת��Ϊ[4, 9, 4]�����У��������ֱַ��Ӧ2,3,4�������֡����ס�����ÿ��ֵȡ��֮�󣬺������ڵ�ֵ��ֱ��ɾ���ˣ�Ϊ�˼��㷽�㣬���ǽ���ת��Ϊ������Ӧ�����飺
    [0, 1, 2, 3, 4]��ʾ���ֱ���
    [0, 0, 4, 9, 4]��ʾѡ������ֵõ��ķ���
    ���ݹ���ѡ��ĳһ�����־Ͳ���ѡ����ǰ��������ˣ��������ת��Ϊ��#198 ��ҽ��ᡷ���⣬ʹ�ö�̬�滮���
*/

int deleteAndEarn(vector<int>& nums)
{
    int size = nums.size();
    int max = 0;
    for (int val : nums)
        max = val > max ? val : max;        
    vector<int> number(max + 1);
    for (int i = 0; i < size; ++i)
        ++number[nums[i]];
    vector<int> dp(max + 1);
    dp[1] = number[1] * 1;
    for (int j = 2; j < number.size(); ++j)
    {
        int cur = dp[j - 2] + number[j] * j;
        dp[j] = dp[j - 1] > cur ? dp[j - 1] : cur;
    }
    return dp[max];
}

