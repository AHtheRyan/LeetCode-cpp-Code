### 词典中最长的单词
### Longest Word in Dictionary

> 给出一个字符串数组 `words` 组成的一本英语词典。返回 `words` 中最长的一个单词，该单词是由 `words` 词典中其他单词逐步添加一个字母组成。  
> 若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。  

> Given an array of strings `words` representing an English Dictionary, return *the longest word in `words` that can be built one character at a time by other words in `words`*.  
> If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.  

----------

#### I 字典树

可以用字典树解决问题，利用字典树的结构，在每一个单词的结尾增加标志位 `isEnd`，可以确定结尾的位置，这样在遍历的过程中就可以实现没增加一个字母就能判断其是否有单词记录  

```cpp
class Tree
{
private:
    vector<Tree* > children;
    bool isEnd;

public:
    Tree()
    {
        this->children = vector<Tree* > (26, nullptr);
        this->isEnd = false;
    }

    bool insert(const string& word)
    {
        Tree* root = this;
        for(const auto& c : word)
        {
            int index = c - 'a';
            if(root->children[index] == nullptr)
                root->children[index] = new Tree;
            root = root->children[index];
        }
        root->isEnd = true;
        return true;
    }

    bool search(const string& word)
    {
        Tree* node = this;
        for(const auto& c : word)
        {
            int index = c - 'a';
            if(node->children[index] == nullptr || !node->children[index]->isEnd)
                return false;
            node = node->children[index];
        }
        return node != nullptr && node->isEnd;
    }
};

class Solution 
{
public:
    string longestWord(vector<string>& words) 
    {
        Tree root;
        for(const auto& word : words)
            root.insert(word);
        string ret;
        for(const auto& word : words)
            if(root.search(word))
                if(word.size() > ret.size() || word.size() == ret.size() && word < ret)
                    ret = word;
        return ret;
    }
};
```
