/*
    apprently, for digital strings of different lengths, the number that can be decoded is cumulative, so we adapt the methode of dynamic programming,
    the dirived relationship is as follows:
    current number       0           1               2               3               4               5               6               7               8               9
    precious number
           0             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           1          dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]
           2          dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]     dp[i-1]         dp[i-1]         dp[i-1]
           3             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           4             0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
           5             0        dp[i-1]         dp[i-1]         ......
           6             0        dp[i-1]         dp[i-1]         ......
           7             0        dp[i-1]         dp[i-1]         ......
           8             0        dp[i-1]         dp[i-1]         ......
           9             0        dp[i-1]         dp[i-1]         ......
    if the number cannot be coded jointly with the previous number, then the number simply adds one bit to the code,
        for example, in "78", the number 8 simply adds one bit to the code but there is no way to increase the code categories;
    if the number can be jointly encoded with the previous number, then the number adds a whole dp[i-2] to the encoding method,
        for example, in "12", the encoding method before the number 1 can be regarded as directly multiplied by 2;
    if the previous number is "1" or "2", and the current number is "0", then this number must be combined with the previous number,
        so the plan is reduced instead, and the number of plans in dp[i-2] is returned;
    if the number is "30" or higher, it cannot be decoded, so there are only 0 options
    follow this idea to build the dp array
*/
/*
    ��Ȼ�����ڲ�ͬ���ȵ����ִ������Խ���������Ǵ����ۼӹ�ϵ�ģ���ֱ�Ӳ��ö�̬�滮��˼·��
    ��ÿ��λ�ò������µĽ��뷽���������Ƶ���ϵ���£�
    ��ǰ����    0           1               2               3               4               5               6               7               8               9
    ǰһ����        
      0        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      1     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]
      2     dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2] dp[i-1]+dp[i-2]     dp[i-1]         dp[i-1]         dp[i-1]
      3        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      4        0        dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]         dp[i-1]
      5        0        dp[i-1]         dp[i-1]         ......
      6        0        dp[i-1]         dp[i-1]         ......
      7        0        dp[i-1]         dp[i-1]         ......
      8        0        dp[i-1]         dp[i-1]         ......
      9        0        dp[i-1]         dp[i-1]         ......
      ������ֲ��ܺ�֮ǰ���������ϱ��룬��ô�����ֵ���Ϊ����������һλ������"78"�У����� 8 �������������һλ����û�����ӱ���ķ�ʽ��
      ��������ܺ�֮ǰ���������ϱ��룬��ô������Ϊ���뷽ʽ������һ���� dp[i-2]������"12"�У������� 1 ֮ǰ�ı��뷽ʽ���Կ���ֱ�ӱ��� 2��
      ���֮ǰ������Ϊ��1�����ߡ�2������ǰ����Ϊ��0������ô�����ֱ�����ǰһ���ֺ���һ�����Է���ʹ�÷��������ˣ��˻� dp[i-2]ʱ �ķ�����Ŀ��
      ����γɵ�����Ϊ"30"�����ϵ���ʮ����ô�޷����룬���Է���ֻ��0��
      ����˼·����dp���鼴��
*/

int numDecodings(string s)
{
    int size = s.size();
    if (size == 1)
        return !(s[0] == '0');
    vector<int> dp(size + 1);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;
    for (int i = 2; i < size + 1; ++i)
    {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (s[i - 2] != '0' && (s[i - 1] - '0' + (s[i - 2] - '0') * 10) <= 26)
            dp[i] += dp[i - 2];
    }
    return dp.back();
}

