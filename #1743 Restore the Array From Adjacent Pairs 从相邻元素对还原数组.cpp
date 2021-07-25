/*
    a relatively significant process is that to know the number of adjacent numbers and the numbers themselves for each number,
    here we can use a hashmap,
    and select a number with one neighbor, put it at the first index of an array,
    traverse the hashmap, put each number in order
*/
/*
    һ���Ƚ���Ҫ�Ĺ����ǣ�֪��ÿ���������ڵ����ֺ͸�����������Բ���һ����ϣ�����洢��
    Ȼ����ȡһ��ֻ��һ���������ֵ����֣�����������еĵ�һλ��Ȼ�����������ϣ����ÿ�������������ηŽ�ȥ����
*/

vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
{
    unordered_map<int, vector<int>> map;
    for (auto pair : adjacentPairs)
    {
        map[pair[0]].push_back(pair[1]);
        map[pair[1]].push_back(pair[0]);
    }

    int size = adjacentPairs.size() + 1;
    vector<int> ret(size);
    for (auto [n, p] : map)
        if (p.size() == 1)
        {
            ret[0] = n;
            break;
        }

    ret[1] = map[ret[0]][0];
    for (int i = 2; i < size; ++i)
    {
        if (map[ret[i - 1]][0] == ret[i - 2])
            ret[i] = map[ret[i - 1]][1];
        else
            ret[i] = map[ret[i - 1]][0];
    }

    return ret;
}