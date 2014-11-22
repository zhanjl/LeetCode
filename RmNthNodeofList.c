struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n)
{
    int i, size, pos;
    struct ListNode *cur;
    if (head == NULL)
        return NULL;
    //计算链表长度
    size = 0;
    cur = head;
    while (cur)
    {
        size++;
        cur = cur->next;
    }
    
    //计算要删除节点的前一个节点位置
    cur = head; 
    pos = size - n;
    //要删除的是第一个节点
    if (pos == 0)
    {
        cur = cur->next;
        return cur;
    }

    for (i = 1; i < pos; i++)
        cur = cur->next;
    cur->next = cur->next->next;
    return head;
}
