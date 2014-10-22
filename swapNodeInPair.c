
struct ListNode {
    int     val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if ( !head || !head->next)
        return head;
    struct ListNode *prev, *cur, *next;
    cur = head;
    next = cur->next;
    head = next;
    
    cur->next = next->next;
    next->next = cur;

    prev = cur;
    cur = prev->next;
    while ( cur && cur->next) {
        next = cur->next;
        cur->next = next->next;
        next->next = cur;
        prev->next = next;

        prev = cur;
        cur = cur->next;
    }
    return head;
}
