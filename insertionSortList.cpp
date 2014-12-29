
ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    ListNode *cur, *sorted, *prev, *beg;
    int val;
    sorted = head->next;
    head->next = NULL;
    cur = head;
    prev = sorted;
    beg = cur;
    while (sorted)
    {
        val = sorted->val;
        while (cur)
        {
            if (cur->val >= val)
                break;
            prev->val = cur->val;
            prev = cur;
            cur = cur->next;
        }
        prev->val = val;
        //下一次迭代的初始化
        cur = sorted;
        sorted = sorted->next;
        cur->next = beg;
        beg = cur;
        prev = sorted; 
    }

    return beg;
}
