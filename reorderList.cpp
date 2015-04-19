//O(n^2)时间复杂度
void reorderList(ListNode *head) 
{
    if (head == NULL)
        return;

    ListNode *cur, *end, *end_prev;

    cur = head;
    
    while (cur->next && cur->next->next) {
        end_prev = cur;
        while (end_prev->next->next)
            end_prev = end_prev->next;
        end = end_prev->next;

        end_prev->next = NULL;
        end->next = cur->next;
        cur->next = end;
        cur = end->next;
    }
     
    return; 
}


//O(n)时间复杂度

//反转链表
ListNode* reverseList(ListNode *head)
{
    if (!head || !head->next)
       return head;
    
    ListNode *prev, *cur, *next;
    
    prev = head;
    cur = head->next;
    
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = NULL;
    return prev;
}

void mergeList(ListNode *first, ListNode *second)
{
    ListNode *fcur, *fnext, *scur, *snext;
    fcur = first, scur = second;
    
    while (fcur && scur) {
        fnext = fcur->next;
        snext = scur->next;
        fcur->next = scur;
        scur->next = fnext;

        fcur = fnext;
        scur = snext;
    } 
}

void reorderList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
        return;

    int cnt;
    ListNode *head1, *head2;
    cnt = 0;
    head1 = head;
    while (head1) {
        cnt++;
        head1 = head1->next;
    } 
    
    
    if (cnt % 2 == 0) {
        cnt = cnt / 2;
    } else {
        cnt = cnt / 2 + 1;
    }

    head2 = head;
    while (--cnt) {
        head2 = head2->next;
    }
    
    head1 = head2;
    head2 = head2->next;

    head1->next = NULL;
    head1 = head;
    head2 = reverseList(head2);
    mergeList(head1, head2);

    return;
}
