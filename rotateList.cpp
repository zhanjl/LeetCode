
ListNode *rotateRight(ListNode *head, int k)
{
    if (head == NULL || k == 0)
        return head;
    ListNode *tail, *cur;
    int len, step;
    cur = head;
    len = 0;
    while (cur)
    {
        len++;
        tail = cur;
        cur = cur->next;
    }
    while (k != 0)
    {
        k--;
        tail->next = head;
        step = len - 1;
        while (step > 1)
        {
            head = head->next;
            step--; 
        }

        cur = head;
        head = tail;
        tail = cur;
        tail->next = NULL;
    }
    
    return head;
}

