/*
    obviously the question is a variant of sorting, in which adding a "number of height higher than this number" to the digit sorting (denoted as k),
    considering how the height affects sorting, it's easy to find that, for the higher people, their k will not change no matter which place the shorter people standing on,
    so we can sort the array by their height, and put the people with lower k in the front, and we can get the result by inserting by their k
*/
/*
    显然题目是一种排序的变体，具体在于为数字排序增加了一个 “比该数字大的数字的个数” 记为 k，
    考虑该因素对身高排序的影响，比较后不难发现，对于身高比较高的人来说，身高低的人站在任何位置都不会影响其 k 值，
    因此，首先我们可以将整个数组按照身高排序，且 k 值较低的排在前面，然后直接根据 k 值进行插值即可
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