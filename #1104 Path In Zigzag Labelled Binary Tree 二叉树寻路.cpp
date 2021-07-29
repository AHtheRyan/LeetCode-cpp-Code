/*
    according to the meaning of the question, the size of the array is the same as the depth of the binary tree, 
    because the even-numbered rows are from left to right, and the odd-numbered rows are from right to left (considering the existence of row 0),
    the distance between each node and the minimum-value node of the depth can be obtained,
    and then the number of the parent node of the node can be obtained according to the order,
    follow this idea to traverse from the leaf node to the root node, and we can get the array
*/
/*
    �������⣬����Ĵ�С��������������ͬ������ż���д������ң������д������󣨿��Ǵ��ڵ�0�У���
    ���Կ������ÿ���ڵ���������С�ڵ�ľ��룬�ٸ������������������ýڵ㸸�ڵ�����֣�
    ���մ�˼·��Ҷ�ӽڵ���������ڵ㼴��
*/

vector<int> pathInZigZagTree(int label)
{
    int n = 0;
    while (pow(2, n + 1) - 1 < label)
        ++n;
    vector<int> route(n + 1);
    route[n] = label;
    int pos;
    int num = label;
    while (n > 0)
    {
        int distance = num - pow(2, n);
        if (n % 2 == 1)
        {
            pos = pow(2, --n) - distance / 2;
            num = pow(2, n) - 1 + pos;
        }
        else
        {
            pos = distance / 2;
            num = pow(2, n--) - 1 - pos;
        }
        route[n] = num;
    }
    route[0] = 1;
    return route;
}