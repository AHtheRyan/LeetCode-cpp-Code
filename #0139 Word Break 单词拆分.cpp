/*
    traverse the whole string, if we find a suitable word at a certain index, we can mark at the following index,
    E.G. in string "leetcode", and dictionary "leet""code", mark index 0 as true, the analyse each index:
    l e e t c o d e
    1 0 0 0 1 0 0 0 1
    we can see that each index that be marked can be seen as a mark of a space,
    annther example:
    c a t s a n d o g
    1 0 0 1 1 0 0 1 0 0
    so we make it to store every word with a boolean algebra, and the last index directly show if its a completely searchable string
    traverse the whole string with the rules above
*/
/*
    遍历整个字符串，如果某个位置到之前的位置存在了符合的单词，那么在该位置后面的位置进行记录，
    例如，对于字符串"leetcode"，和字典"leet""code"，先标记第一个位置为true，接下来对每个位置进行分析：
    l e e t c o d e 
    1 0 0 0 1 0 0 0 1
    可见，每一个标记的位置都可以视为一个可以查找到的单词的末尾，或者说是一个空格，标记表示了每个空格的位置，
    再看"catsandog",和字典"cats""dog""sand""and""cat"，
    c a t s a n d o g
    1 0 0 1 1 0 0 1 0 0
    这样就实现了使用一个bool类型数组将每个单词都标记，且最后一位直接说明了是否是完整的可查字符串，
    按上述规则遍历整个字符串即可
*/ 

bool wordBreak(string s, vector<string>& wordDict)
{
    unordered_set<string> wordStore;
    for (auto word : wordDict)
        wordStore.insert(word);
    int size = s.size() + 1;
    vector<bool> dp(size);
    dp[0] = true;
    for (int i = 1; i < size; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (dp[j] && wordStore.find(s.substr(j, i - j)) != wordStore.end())
            {
                dp[i] = true;
                break;
            }
    }
    return dp[size - 1];
}