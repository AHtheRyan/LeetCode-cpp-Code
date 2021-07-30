/*
    obviously the question is a variant of sorting, in which adding a "number of height higher than this number" to the digit sorting (denoted as k),
    considering how the height affects sorting, it's easy to find that, for the higher people, their k will not change no matter which place the shorter people standing on,
    so we can sort the array by their height, and put the people with lower k in the front, and we can get the result by inserting by their k
*/
/*
    ��Ȼ��Ŀ��һ������ı��壬��������Ϊ��������������һ�� ���ȸ����ִ�����ֵĸ����� ��Ϊ k��
    ���Ǹ����ض���������Ӱ�죬�ȽϺ��ѷ��֣�������߱Ƚϸߵ�����˵����ߵ͵���վ���κ�λ�ö�����Ӱ���� k ֵ��
    ��ˣ��������ǿ��Խ��������鰴����������� k ֵ�ϵ͵�����ǰ�棬Ȼ��ֱ�Ӹ��� k ֵ���в�ֵ����
*/

vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
{
    int size = people.size();
    vector<vector<int>> resort;
    sort(people.begin(), people.end(), [](vector<int>a, vector<int>b) {return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]; });
    for (auto& person : people)
        resort.insert(resort.begin() + person[1], person);
    return resort;
}