### 复杂链表的复制

> 请实现 `copyRandomList` 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 `next` 指针指向下一个节点，还有一个 `random` 指针指向链表中的任意节点或者 `null`。  

----------

#### I 回溯

见[复制带随机指针的链表](./%230138%20Copy%20List%20with%20Random%20Pointer%20复制带随机指针的链表.md)  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution 
{
private:
    unordered_map<Node*, Node*> mp;

public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return nullptr;
        if(!mp.count(head))
        {
            Node* cur = new Node(head->val);
            mp[head] = cur;
            cur->next = copyRandomList(head->next);
            cur->random = copyRandomList(head->random);
        }
        return mp[head];
    }
};
```

#### II 模拟

见[复制带随机指针的链表](./%230138%20Copy%20List%20with%20Random%20Pointer%20复制带随机指针的链表.md)  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution 
{
private:
    unordered_map<Node*, Node*> mp;

public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return nullptr;
        Node* cur = new Node(head->val);
        mp[head] = cur;
        copy(head, cur);
        return cur;
    }

    void copy(Node* head, Node* cur)
    {
        while(head)
        {
            Node* nxt = head->next;
            if(mp.count(nxt))
                cur->next = mp[nxt];
            else if(nxt)
            {
                cur->next = new Node(nxt->val);
                mp[nxt] = cur->next;
            }
            Node* rdm = head->random;
            if(mp.count(rdm))
                cur->random = mp[rdm];
            else if(rdm)
            {
                cur->random = new Node(rdm->val);
                mp[rdm] = cur->random;
            }
            head = head->next;
            cur = cur->next;
        }
    }
};
```
