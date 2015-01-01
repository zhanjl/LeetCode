//反转beg和end之间的链表节点
void reverse(ListNode *beg, ListNode *end)
{
    ListNode *prev, *cur, *next;
    prev = beg;
    cur = prev->next;
    next = cur->next;

    while (cur && cur != end)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }

    cur->next = prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    int cnt;
    //beg和end表示要反转的节点 
    //prev表示beg的前一个节点
    //next表示end的后一个节点
    ListNode *prev, *next, *beg, *end;  
    
    //单独处理第一段
    beg = end = head;
    cnt = 1;
    while (end && cnt < k)
    {
        end = end->next;
        cnt++;
    }
    if (end == NULL)
        return head;
    next = end->next;
    reverse(beg, end);
    beg->next = next;
    head = end;

    while (1)
    {
        prev = beg;
        beg = end = beg->next;

        cnt = 1;
        while (end && cnt < k)
        {
            end = end->next;
            cnt++;
        }
        if (end == NULL)
            break;
        next = end->next;
        reverse(beg, end);
        beg->next = next;
        prev->next = end;
    }

    return head;
}
