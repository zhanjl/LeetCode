struct ListNode {
    int     val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n)
{
    struct ListNode *prev, *cur, *next;
    struct ListNode *beg, *end;
    int count;
    count = 1;
    beg = head;
    prev = NULL;
    
    while (count != m)
    {
        count++;
        prev = beg;
        beg = beg->next;
    }

    end = beg;
    while (count != n)
    {
        count++;
        end = end->next;
    }

    cur = beg;
    next = cur->next;

    while (cur != end)
    {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }

    cur->next = prev;
     
    prev = beg->next;

    if (prev != NULL)
        prev->next = cur;
    beg->next = next;
    
    if (beg == head)
        head = cur;
    return head;
}
