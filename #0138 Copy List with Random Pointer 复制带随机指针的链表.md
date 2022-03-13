### 复制带随机指针的链表
### Copy List with Random Pointer

> 给你一个长度为 `n` 的链表，每个节点包含一个额外增加的随机指针 `random`，该指针可以指向链表中的任何节点或空节点。  
> 构造这个链表的`深拷贝`。深拷贝应该正好由 `n` 个**全新**节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 `next` 指针和 `random` 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。**复制链表中的指针都不应指向原链表中的节点**。  
> 例如，如果原链表中有 `X` 和 `Y` 两个节点，其中 `X.random --> Y`。那么在复制链表中对应的两个节点 `x` 和 `y`，同样有 `x.random --> y`。  
> 返回复制链表的头节点。  
> 用一个由 `n` 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：  
> - `val`：一个表示 `Node.val` 的整数。  
> - `random_index`：随机指针指向的节点索引（范围从 `0` 到 `n-1`）；如果不指向任何节点，则为 `null`。  
> 
> 你的代码**只**接受原链表的头节点 `head` 作为传入参数。  

> A linked list of length `n` is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.  
> Construct a `deep copy` of the list. The deep copy should consist of exactly `n` **brand new** nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. **None of the pointers in the new list should point to nodes in the original list**.  
> For example, if there are two nodes `X` and `Y` in the original list, where `X.random --> Y`, then for the corresponding two nodes `x` and `y` in the copied list, `x.random --> y`.  
> Return *the head of the copied linked list*.  
> The linked list is represented in the input/output as a list of `n` nodes. Each node is represented as a pair of `[val, random_index]` where:  
> - `val`: an integer representing `Node.val`  
> - `random_index`: the index of the node (range from `0` to `n-1`) that the `random` pointer points to, or `null` if it does not point to any node.  
> 
> Your code will **only** be given the `head` of the original linked list.  

----------

#### I 迭代

先通过迭代，建立只包含 `next` 的链表，同时利用哈希表记录每个原链表节点对应的新节点  
再通过一轮迭代，建立 `random` 链表，利用哈希表获得每个原链表节点的随机节点位置  

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
        Node* root = new Node(head->val);
        Node* dummyhead = root;
        mp[head] = root;
        Node* tmp = head;
        while(head->next)
        {
            head = head->next;
            Node* cur = new Node(head->val);
            root->next = cur;
            root = root->next;
            mp[head] = root;
        }
        root = dummyhead;
        while(root)
        {
            if(tmp->random)
                root->random = mp[tmp->random];
            else
                root->random = nullptr;
            root = root->next;
            tmp = tmp->next;
        }
        return dummyhead;
    }
};
```

#### II 回溯

利用回溯的方法，先确定当前节点是否被处理过，如果没有，则创建当前值的节点，同时对当前节点的 `next` 和 `random` 做相同处理  

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
