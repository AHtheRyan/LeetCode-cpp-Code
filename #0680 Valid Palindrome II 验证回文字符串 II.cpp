/*
    此题显然用双指针会很快解出，对于 left 和 right 两个变量的设置如下：
    1. 如果 s[left] == s[right]，始终成立，则遍历到最后返回 true 即可
    2. 如果 s[left] != s[right]：
        2.1 按照同样的思路，初始化双指针起点为 left + 1，right，遍历一次
        2.2 按照同样的思路，初始化双指针起点为 left，right - 1，遍历一次
        2.3 如果两次遍历都不是回文，则返回false，否则返回true
*/

bool validPalindrome(string s)
{
    int size = s.size();
    int left = 0;
    int right = size - 1;
    bool check1 = true;
    bool check2 = true;
    while (left <= right)
    {
        if (s[left] != s[right])
        {
            check1 = check(left, right - 1, s);
            check2 = check(left + 1, right, s);
            break;
        }
        ++left;
        --right;
    }
    return check1 || check2;
}

bool check(int start, int end, string s)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            break;
        ++start;
        --end;
        if (start >= end)
            return true;
    }
    return false;
}