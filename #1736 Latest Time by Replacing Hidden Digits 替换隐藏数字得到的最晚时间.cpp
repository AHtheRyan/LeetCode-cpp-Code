/*
    rules:
    consider hour:
    1.1 if ones is ?, then tens is 2
    1.2 if ones is 0 ~ 3, then ones is 2
    1.3 if ones is 4 ~ 9, then ones is 1
    2.1 if tens is 0 ~ 1, then ones is 9
    2.2 if tens is 2, then ones is 3
    consider minute:
    3. tens is 5
    4. ones is 9
*/
/*
    �ж��������£�
    �����Сʱ��
    1.1 �����λΪ ?����ôʮλΪ 2
    1.2 �����λΪ 0 ~ 3����ô��λΪ 2
    1.3 �����λΪ 4 ~ 9����ô��λΪ 1
    2.1 ���ʮλΪ 0 ~ 1����ô��λΪ 9
    2.2 ���ʮλΪ 2����ô��λΪ 3
    ����Ƿ��ӣ�
    3. ʮλΪ5
    4. ��λΪ9
*/

string maximumTime(string time)
{
    if (time[0] == '?')
    {
        if (time[1] == '?' || time[1] >= '0' && time[1] <= '3')
            time[0] = '2';
        else
            time[0] = '1';
    }
    if (time[1] == '?')
        time[1] = (time[0] != '2') ? '9' : '3';
    if (time[3] == '?')
        time[3] = '5';
    if (time[4] == '?')
        time[4] = '9';
    return time;
}
