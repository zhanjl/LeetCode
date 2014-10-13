
struct ListNode {
    int     val;
    struct ListNode *next;
};

struct ListNode *nextNode(struct ListNode *cur) 
{
    while (cur && cur->next) {
        if (cur->val != cur->next->val)
            break;
        cur = cur->next;
    }
    return cur->next;
}
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode *cur, *next;
    
    while (head && head->next) {
        if (head->val != head->next->val)
            break;
        head = nextNode(head);
    } 

    cur = head;
    while (cur) {
        next = cur->next;
        while (next && next->next) {
            if (next->val != next->next->val)
                break;
            next = nextNode(next);
        }
        cur->next = next;
        cur = next;
    }

    return head;
}
