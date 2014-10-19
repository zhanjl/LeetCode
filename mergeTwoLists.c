struct ListNode {
    int     val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *head, *cur;
    struct ListNode *next1, *next2;

    if (l1 == NULL) 
        return l2;
    if (l2 == NULL)
        return l1;

    if (l1->val < l2->val) {
        head = l1;
        next2 = l2;
    } else {
        head = l2;
        next2 = l1;
    }
    cur = head;
    next1 = head->next;
    while (next1 && next2) {
        if (next1->val < next2->val) {
            cur->next = next1;
            cur = next1;
            next1 = next1->next;
        }  else {
            cur->next = next2;
            cur = next2;
            next2 = next2->next;
        }
    }
    if (next1 == NULL)
        cur->next = next2;
    else if (next2 == NULL)
        cur->next = next1;
    return head;
}
