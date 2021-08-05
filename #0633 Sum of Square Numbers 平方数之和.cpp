/*
    此题为 #167 两数之和II 的变体，
    区别在于此处 left 和 right 的变量都变为平方，
    采用双指针可以轻松求解，
    注意平方和可能会导致溢出，需要改变判断条件
*/ 

bool judgeSquareSum(int c)
{
    int left = 0;
    int right = sqrt(c);
    while (left <= right)
    {
        if (right * right == c - left * left)
            return true;
        else if (right * right > c - left * left)
            --right;
        else
            ++left;
    }
    return false;
}