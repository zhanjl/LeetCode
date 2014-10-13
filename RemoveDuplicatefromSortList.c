struct ListNode {
    int     val;
    ListNode *next;
};

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *cur, *next;
    cur = head;
    while (cur) {
        next = cur->next;
        while (next) {
            if (next->val != cur->val)
                break;
            next = next->next;
        }
        cur->next = next;
        cur = next;
    }
    return head;
}
