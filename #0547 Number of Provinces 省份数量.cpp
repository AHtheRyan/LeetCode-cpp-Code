/*
    ���������ĳ��� i �� j �໥��Ȼ������ isConnected[i][j] == isConnected[j][i] == 1 �Ĺ�ϵ��
    ��ˣ�����ֻҪͨ��ĳ�ַ�ʽ��ȷ��������ϵ���� isConnected ʱ�����ظ��������ɣ�
    ����������˼·��
    1. ���ñ�־λ���������ĳ��м�Ϊ true��δ������Ϊ false
    2. �����������໥���й�ϵ�� 1 �ı�Ϊ 0
    �����Ϳ��������������������ÿ��ʡ�ݵĹ�ϵ��������ж�
*/

//���ñ�־λ
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; ++i)
        {
            if (!visited[i])
            {
                mark(isConnected, visited, i);
                ++ret;
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
    {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j)
            if (isConnected[i][j] == 1 && !visited[j])
                mark(isConnected, visited, j);
    }
};


//�ı䷽����
class Solution
{
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int size = isConnected.size();
        int ret = 0;
        for (int i = 0; i < size; ++i)
        {
            if (isConnected[i][i] == 1)
            {
                ++ret;
                mark(isConnected, i);
            }
        }
        return ret;
    }

    void mark(vector<vector<int>>& isConnected, int i)
    {
        for (int j = 0; j < isConnected.size(); ++j)
        {
            if (isConnected[i][j] == 1)
            {
                isConnected[i][j] = 0;
                isConnected[j][i] = 0;
                if (i != j)
                    mark(isConnected, j);
            }
        }
    }
};
