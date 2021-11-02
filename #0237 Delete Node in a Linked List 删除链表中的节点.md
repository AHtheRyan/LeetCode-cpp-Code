### 删除链表中的节点
### Delete Node in a Linked List

> 请编写一个函数，用于 **删除单链表中某个特定节点**。在设计函数时需要注意，你无法访问链表的头节点 `head`，只能直接访问 **要被删除的节点**。  
> 题目数据保证需要删除的节点 **不是末尾节点**。  

> Write a function to **delete a node** in a singly-linked list. You will **not** be given access to the `head` of the list, instead you will be given access to **the node to be deleted** directly.  
> It is **guaranteed** that the node to be deleted is **not a tail node** in the list.  

----------

#### I 替代

将当前节点的值表示为下一个节点的值，并将 `next` 指针指向下下一个节点即可

```cpp
void deleteNode(ListNode* node) 
{
    node->val = node->next->val;
    node->next = node->next->next;
}
```
