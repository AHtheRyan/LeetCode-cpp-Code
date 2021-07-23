/*
    different child has different greed factor, we try giving small cookies to low greed-factor child,
    so sort the children and cookies from small to large:
    1. if cookie is smaller, change it into a bigger one and try again,
    2. if greed factor is smaller, give it to the child and change to the next child and cookie, and count the child,
    the number of content children is the number we counted
*/
/*
    因为每个小朋友胃口不同，我们尽可能将小的饼干给胃口小的孩子，现将小孩胃口和饼干尺寸按从小到大排序，
    每次都将最小的饼干给胃口最小的小孩：
    1. 如果饼干小了，就换成大一些的饼干，放弃当前这块饼干
    2. 如果孩子胃口小了，那么可以直接喂，再考虑下一个孩子和下一个饼干，并计数孩子
    最后孩子的数量就是喂饱的数量

*/ 

int findContentChildren(vector<int>& g, vector<int>& s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0;
    int coNum = 0;
    while (coNum < s.size() && count < g.size())
    {
        if (g[count] <= s[coNum])
            ++count;
        ++coNum;
    }
    return count;
}