/*
    利用队列先进后出的特性可以快速解决此题：
    依次将每个人加入队列，之后：
    1. 设置计数位 count = 0
    2. 依次将队列最前面的元素出队，并将 count 加一
        2.1 如果 count != k，则将出队的元素加到队列的末尾
        2.2 如果 count == k，则将 count 置为 0
    3. 当队列只剩一个元素，将该元素返回即可
*/ 

int findTheWinner(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);
    int count = 0;
    while (q.size() > 1)
    {
        ++count;
        if (count == k)
        {
            count = 0;
            q.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }
    return q.front();
}