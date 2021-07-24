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
    判断条件如下：
    如果是小时：
    1.1 如果个位为 ?，那么十位为 2
    1.2 如果个位为 0 ~ 3，那么个位为 2
    1.3 如果个位为 4 ~ 9，那么个位为 1
    2.1 如果十位为 0 ~ 1，那么个位为 9
    2.2 如果十位为 2，那么个位为 3
    如果是分钟：
    3. 十位为5
    4. 个位为9
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
