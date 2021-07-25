/*
    a relatively significant process is that to know the number of adjacent numbers and the numbers themselves for each number,
    here we can use a hashmap,
    and select a number with one neighbor, put it at the first index of an array,
    traverse the hashmap, put each number in order
*/
/*
    一个比较重要的过程是，知道每个数字相邻的数字和个数，这里可以采用一个哈希表来存储，
    然后任取一个只有一个相邻数字的数字，将其放在数列的第一位，然后遍历检索哈希表，将每个相邻数字依次放进去即可
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