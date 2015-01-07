
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    int left, sum;
    ListNode *cur1, *cur2;
    cur1 = l1, cur2 = l2;
    left = 0;
    
    while (cur1->next && cur2->next)
    {
        sum = cur1->val + cur2->val + left;
        cur1->val = sum % 10;
        left = sum / 10;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    
    sum = cur1->val + cur2->val + left;
    cur1->val = sum % 10;
    left = sum / 10;

    if (cur1->next == NULL)
    {
        cur1->next = cur2->next;
    }
     
    while (cur1->next)
    {
        cur1 = cur1->next;
        sum = cur1->val + left;
        cur1->val = sum % 10;
        left = sum / 10;
    }

    if (left != 0)
    {
        cur1->next = new ListNode(left);
    }

    return l1;
}
