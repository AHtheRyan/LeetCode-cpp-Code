/*
    显然，满足是 x 的平方根的条件是，该数字的平方 ≤ x，且该数字+1的平方 ＞ x，
    因此，利用二分法寻找该数字即可
*/ 

int mySqrt(int x)
{
    if (x == 0 || x == 1)
        return x;
    int left = 0;
    int right = x;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int next = mid + 1;
        if (mid <= x / mid && next > x / next)
            return mid;
        else if (mid < x / mid)
            left = mid + 1;
        else
            right = mid;
    }
    return -1;
}