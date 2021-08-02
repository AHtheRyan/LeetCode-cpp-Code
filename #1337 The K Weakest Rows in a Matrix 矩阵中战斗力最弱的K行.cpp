/*
    首先可以使用二分法确定每行的战斗力，
    之后将战斗力按照从小到大的顺序加进优先队列中，
    再把前 k 个队列中的元素出队并放入返回的数组中即可
*/

vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
{
    int size = mat.size();
    vector<vector<int>> row(size, vector<int>(2));
    for (int i = 0; i < size; ++i)
        row[i] = { findPower(mat[i]), i };
    priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>> q(row.begin(), row.end());
    vector<int> ret;
    for (int i = 0; i < k; ++i)
    {
        ret.push_back(q.top()[1]);
        q.pop();
    }
    return ret;
}

int findPower(vector<int> line)
{
    int size = line.size();
    int left = 0;
    int right = size - 1;
    int mid;
    int pos = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (line[mid])
        {
            pos = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return pos + 1;
}