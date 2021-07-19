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
    ������ÿ��λ�ô���ǰλ�ÿ���ǰ���ľ��룬���ݹ���ÿǰ��һ�񣬾ͻ�����һ��ֵ�����ǿ��Կ��������������磬������[2, 3, 1, 1, 4]�У��� ��2�� ǰ���� ��3����������1�㡰��������
    ����ǰ������һ������ ��1����
    1. �� ��2�� ǰ������һ�� ��1����������2�㡰���������� ��1�� �����»��1��������
    2. �ȴ� ��2�� �� ��3���� �ٴ� ��3�� �ٵ� ��1������ʱ����1�������������Լ���ǰ����ͣ������ͼ��ø���������ֱ���ҵ�������ߵ�λ��ͣ������
    Ҳ����˵�����տ��ǵľ��ǰ�˳�򵽴�ÿ��λ�ÿ��Ի�õ���������Ƕ��٣�ֱ��û���������ߵ��յ㣬
    ��ˣ����Թ���dp���飬��¼ÿ��λ�õ��������ֵ���������1��2������ֵΪǰһ��ֱ��ǰ������������·����ͣ�����͵�ǰ���ӵ�������ͣ�ڴ˸������������ߵĽϴ��ߣ�
    ��������޷�·����Ҳ����ǰһ���ʣ������Ϊ0����ֱ���޷�ǰ��������false�������������󣬷���true
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
//��ǰ��Ļ����������޸ģ�ʹ��һ������rightmost��¼ÿ�����ӿ���ǰ�������ֵ
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

