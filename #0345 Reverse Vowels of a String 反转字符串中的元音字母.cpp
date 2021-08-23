/*
    经典使用 哈希表 + 双指针 解决的题目，
    分别从最左和最右遍历整个字符串，遇到元音字母时将两者交换，
    如果左指针遍历到了右指针的右边，则停止遍历
*/

string reverseVowels(string s)
{
    unordered_set<char> rec{ 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    int left = 0;
    int right = s.size() - 1;
    while (left <= right)
    {
        while (rec.find(s[left]) == rec.end() && left <= right)
            ++left;
        while (rec.find(s[right]) == rec.end() && left <= right)
            --right;
        if (rec.find(s[left]) != rec.end() && rec.find(s[right]) != rec.end())
            swap(s[left++], s[right--]);
    }
    return s;
}