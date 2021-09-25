### 扁平化多级双向链表
### Flatten a Multilevel Doubly Linked List

> 多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。  
> 给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。  

> You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.  
> Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.  

----------

#### I 深度优先搜索 + 栈

我们可以对整个链表进行深度优先搜索，同时将 `child` 节点转化为 `next` 节点，搜索思路如下：  
1. 如果当前节点存在 `child` 节点，那么将其 `next` 节点（如果有）存储在栈中，并将其 `child` 节点改成 `next` 节点，然后**以其为起点进行搜索操作**  
2. 如果当前节点不存在 `child` 节点与 `next` 节点，则  
   - 如果栈为空，说明所有待处理的 `next` 节点都处理完毕，直接返回即可  
   - 如果栈不为空，则将栈顶的节点作为当前最后一个节点的 `next` 节点，然后**以其为起点进行搜索操作**  
3. 如果当前节点只有 `next` 节点，则将 `next` 节点作为新节点，**以其为起点进行搜索操作**  
4. 如果当前节点为空，或当前节点无 `child` 和 `next` 节点，栈也为空，则直接返回  

以此实现DFS的逻辑架构即可  

```cpp
Node* flatten(Node* head) 
{
    Node* phead = new Node;
    phead->next = head;
    stack<Node*> stk;
    dfs(head, stk);
    return phead->next;
}

void dfs(Node* head, stack<Node*> stk)
{
    if(!head || !head->next && !head->child && stk.empty())
        return ;
    if(!head->next && !head->child)
    {
        head->next = stk.top();
        head->next->prev = head;
        stk.pop();
    }
    else if(head->child)
    {
        if(head->next)
            stk.push(head->next);
        head->next = head->child;
        head->next->prev = head;
        head->child = nullptr;
    }
    head = head->next;
    dfs(head, stk);
}
```
