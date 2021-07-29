/*
    transfer the problrm into a base conversion problem
*/
/*
    直接转换成进制问题即可
*/ 

int titleToNumber(string columnTitle)
{
    int ret = 0;
    for (int k = 0; k < columnTitle.size(); ++k)
        ret = ret * 26 + (columnTitle[k] - 'A' + 1);
    return ret;
}