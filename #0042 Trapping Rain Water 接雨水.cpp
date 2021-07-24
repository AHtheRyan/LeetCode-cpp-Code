/*
    according to the question, the first bar cannnot trap any water,
    traverse the array from the left to the right, we can analyse each bar as below:
    1. the bar is taller than the left one, then the position will not trap any water
    2. the bar is shorter than the left one, then the volume of trapped water = trapped water in the left + difference of these two bars
    according to this analysis, we can get a map of trapped water,
    but here is the question:
    under this ciucumstence, the trapped water surface on the right of the highest bar will always be equal to the height of the highest,
    the silution is simple, traverse the array from the right to the left, and we can analyse the real condition of the right hand side,
    the result will be the summary of the minimum volume of each site
*/
/*
    �������⣬������ʼλ�õ����Ӵ��ǲ������л�ˮ�ģ��������ҿ�����ÿ��λ�ã�����ÿ��λ���ܻ�ˮ������
    1. ��λ�õ����ӱ����ĸߣ���ô��λ�ñ�Ȼ�޻�ˮ
    2. ��λ�õ����ӱ����ĵͣ���ô��λ�õĻ�ˮΪ ���Ļ�ˮ + �����ӸߵĲ�ֵ
    ���ݴ˷��������Ǳ����������飬���Եõ�һ����ˮ�ֲ���
    ���˴��и����⣺�ڴ�����£���ߵ������Ҳ�Ļ�ˮʼ�����������ƽ�У�
    �������Ҳ�ܼ򵥣����������ٱ���һ�����飬��ʱ���Խ���������Ҳ�Ļ�ˮ��������꣬
    ��ʱ���Խ�������ˮ�ֲ���ÿ��λ�õ���Сֵ��ӣ������������ˮ��
*/

int trap(vector<int>& height)
{
    if (height.empty())
        return 0;
    int size = height.size();
    vector<int> dpl(size);
    vector<int> dpr(size);
    dpl[0] = 0;
    dpr[size - 1] = 0;
    for (int i = 1; i < size; ++i)
    {
        int delta = height[i - 1] - height[i];
        dpl[i] = dpl[i - 1] + delta > 0 ? dpl[i - 1] + delta : 0;
    }
    for (int j = size - 2; j >= 0; --j)
    {
        int delta = height[j + 1] - height[j];
        dpr[j] = dpr[j + 1] + delta > 0 ? dpr[j + 1] + delta : 0;
    }
    vector<int> rain(size);
    for (int k = 0; k < size; ++k)
        rain[k] = dpl[k] > dpr[k] ? dpr[k] : dpl[k];
    int sum = 0;
    for (auto water : rain)
        sum += water;
    return sum;
}
