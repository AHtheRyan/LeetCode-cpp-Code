/*
    根据题意，不成对的单独'('或者')'为无效的括号，因此，无效括号存在的可能情况如下：
    1. 出现了')'，但之前没有可以配对的'('
    2. 出现了'('，但之后没有可以配对的')'
    我们采用栈来解决此类问题：
    创建两个栈，分别用来记录遇到的未配对的'('与相应的下标，
    遍历整个字符串：
    1. 如果遇到字母，则pass
    2. 如果遇到'('，则将其堆入栈中，同时记录该位置的下标 index
    3. 如果遇到')'
        3.1 如果栈为空，则该')'必然无法配对，将其和其下标堆入两个栈中
        3.2 如果栈顶元素不为'('而是')'，则无法配对，将其和其下标堆入栈中
        3.3 否则，将栈中的'('出栈
    处理完之后，如果是空栈，则返回原字符串，否则，输出字符串时跳过栈中所有下标对应的括号
*/

string minRemoveToMakeValid(string s)
{
    stack<char> stk;
    stack<int> index;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == '(')
        {
            stk.push('(');
            index.push(i);
        }
        else if (s[i] == ')')
        {
            if (!stk.empty() && stk.top() == '(')
            {
                stk.pop();
                index.pop();
            }
            else
            {
                stk.push(')');
                index.push(i);
            }
        }
    }
    vector<int> vec;
    while (!index.empty())
    {
        vec.push_back(index.top());
        index.pop();
    }
    int num = vec.size();
    if (num == 0)
        return s;
    int indexptr = num - 1;
    int ptrs = 0;
    string ret = "";
    while (ptrs < size)
    {
        if (indexptr >= 0 && ptrs == vec[indexptr])
        {
            --indexptr;
            ++ptrs;
        }
        else
            ret += s[ptrs++];
    }
    return ret;
}