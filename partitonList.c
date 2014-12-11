
struct ListNode {
    int             val;
    struct ListNode* next;
};

struct ListNode* partition(struct ListNode *head, int x)
{
    struct ListNode *insert, *cur;
    struct ListNode *temp;
    if (head == NULL)
        return NULL;

    if (head->val < x)
        insert = head;
    else
        insert = NULL;

    cur = head;
    while (cur->next)
    {
        if (cur->next->val < x)
        {
            if (cur == insert)
            {
                cur = cur->next;
                insert = cur;
                continue;
            }
            temp = cur->next;
            cur->next = cur->next->next;
            if (insert == NULL)
            {
                insert = temp;
                insert->next = head; 
                head = insert;
            }
            else
            {
                temp->next = insert->next;
                insert->next = temp;
                insert = temp;
            }
        }
        else
            cur = cur->next;
    }
    return head;
}
