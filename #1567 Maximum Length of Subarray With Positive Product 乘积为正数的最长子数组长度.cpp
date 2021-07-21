/*
    we can naturally think about solving the problem with Dynamic Pogramming if we have done #53 and #152,
    obviouly there is relationship between negative and positive number in the array, so we can create two variables to store numbers of positive and negtive number, here are the solution:
    1. current number is 0:
       no matte what thr number before current index is, the counting will stop here and we should set two variables into 0
    2. current number is positive:
        2.1 if positive number count is not 0, we can add 1 to it, because pos �� pos = pos
        2.2 if negative number count is not 0, we can add 1 to it, because neg �� pos = neg
        2.3 if positive number count is 0, we can add 1 to it, because postive number count is already set to 0
        2.4 if negative number count is 0, the negative number count stays still
    3. current number is negative:
        3.1 if positive number count is not 0, we can add 1 to negative number count, because pos �� neg = neg
        3.2 if negative number count is not 0, we can add 1 to positive number count, because neg �� neg = pos
        3.3 if positive number count is 0, then negative number count = positive number count + 1, because postive number count is already set to 0
        3.4 if negative number count is 0, then posative number count stays 0
    E.G. in array [2, -2, -3, -4, 3, 5�� -1], initial pos_num_count = 1 and neg_num_cunt = 0 because the first number is 2, according to the rules:
    at position -2, pos_num_count = 0, neg_num_count = 1
    at position -3, pos_num_count = 2, neg_num_count = 1
    at position -4, pos_num_count = 2, neg_num_count = 3
    at position  3, pos_num_count = 3, neg_num_count = 4
    at position  5, pos_num_count = 4, neg_num_count = 5
    at position -1, pos_num_count = 6, neg_num_count = 5
*/
/*
    �����γ���������˻���������� #53 �������ͣ�#152�˻���������飬��Ȼ��Ȼ���뵽ʹ�ö�̬�滮�ķ�ʽ�����
    ��Ȼ����Ŀ��������֮����ڹ�ϵ��ֻ���ڸ���ת��Ϊ����������ת��Ϊ�����ļ���λ�ã����ڱ����Ĵ������Ѷȣ������ǿ��Դ������������ֱ���������͸�������Ŀ������Ϊ����취��
    1. ���ǵ�ǰ������Ϊ0
       ��Ϊ��ǰ����Ϊ0�����Բ���ǰ��������Ƕ��٣��˴�����������ֹ�������͸����ĳ��ȼ���������
    2. ���ǵ�ǰ����Ϊ����
        2.1 ����������ȼ�����Ϊ0����ô��ʱ���Ը������ĳ��ȼ���+1����Ϊ����������=����
        2.2 ����������ȼ�����Ϊ0����ô��ʱ���Ը������ĳ��ȼ���+1����Ϊ����������=����
        2.3 ����������ȼ���Ϊ0����ô��ʱ���Ը������ĳ��ȼ���+1����Ϊ���� 1 ���������㣨�ɹ���2.1�������
        2.4 ����������ȼ���Ϊ0����ô��ʱ�����ĳ���Ϊ0����
    3. ���ǵ�ǰ����Ϊ����
        3.1 ����������ȼ�����Ϊ0����ô��ʱ�����ĳ��ȼ��� = �����ĳ��ȼ��� + 1����Ϊ����������=����
        3.2 ����������ȼ�����Ϊ0����ô��ʱ�����ĳ��ȼ��� = �����ĳ��ȼ��� + 1����Ϊ����������=����
        3.3 ����������ȼ���Ϊ0����ô��ʱ�����ĳ��ȼ��� = �����ĳ��ȼ��� + 1����Ϊ���� 1 ���������㣨�ɹ���3.1�������
        3.4 ����������ȼ���Ϊ0����ô��ʱ�����ĳ���Ϊ0����
    ������� 7 �����
    ���磬������[2, -2, -3, -4, 3, 5�� -1]�У���Ϊ��һ������Ϊ2�����Գ�ʼֵ��������=1����������=0�����ݹ���
    ��-2λ�ã��������� = 0���������� = 1
    ��-3λ�ã��������� = 2���������� = 1
    ��-4λ�ã��������� = 2���������� = 3
    �� 3λ�ã��������� = 3���������� = 4
    �� 5λ�ã��������� = 4���������� = 5
    ��-1λ�ã��������� = 6���������� = 5
    ���Կ��Է��������6
*/

int getMaxLen(vector<int>& nums)
{
    int size = nums.size();
    int negcount = 0;
    int poscount = 0;

    if (nums[0] > 0)
        ++poscount;
    if (nums[0] < 0)
        ++negcount;

    int maxlen = poscount;
    for (int i = 1; i < size; ++i)
    {
        int preneg = negcount;
        int prepos = poscount;
        if (nums[i] > 0)
        {
            poscount = poscount + 1;
            negcount = (preneg == 0) ? 0 : (preneg + 1);
        }
        if (nums[i] < 0)
        {
            negcount = prepos + 1;
            poscount = (preneg == 0) ? 0 : (preneg + 1);
        }
        if (nums[i] == 0)
            poscount = negcount = 0;
        maxlen = poscount > maxlen ? poscount : maxlen;
    }

    return maxlen;
}