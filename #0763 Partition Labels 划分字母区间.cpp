/*
    the key point of this problem is that each length of a substring depends on the index that it shows the last time,
    in other words, the range of the first and last occurrence of each letter can be regarded as an interval,
    and the question can be transformed into a overlapped interval problem,
    we use a hash map to store the last index a letter shows,
    and we can traverse the string and compare every last index with current substring rightside,
    if the letter is on the right side of the substring, we can divide the previous substring,
    return the number of the substrings
*/
/*
    此题关键点在于，每段字符串的长度是由该段中最后一个单词出现的最后一个位置决定的，
    换句话说，我们可以将每个字母第一次和最后一次出现的范围看做一个区间，
    那么这题就可以转化为将重叠区间累加的问题，
    利用一个哈希表存储每个字母出现的最后位置，遍历字符串，比较每个字母最后出现的位置和当前的子字符串的最右端，
    如果字母在子字符串内，则不考虑，如果字母出现的位置在当前子字符串的后面，那么可以将前面的子字符串划分出来，
    最后返回总的子字符串数目即可
*/

vector<int> partitionLabels(string s)
{
    int size = s.size();
    vector<int> index(26);
    vector<int> ret;
    for (int i = 0; i < size; ++i)
        index[s[i] - 'a'] = i;
    int left = 0;
    int right = index[s[0] - 'a'];
    for (int j = 0; j < size; ++j)
    {
        if (j <= right)
            right = max(index[s[j] - 'a'], right);
        else
        {
            ret.push_back(right - left + 1);
            left = j;
            right = index[s[j] - 'a'];
        }
    }
    ret.push_back(right - left + 1);

    return ret;
}