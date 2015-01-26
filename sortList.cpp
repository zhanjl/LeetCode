//使用快排会超时，所以要使用归并排序
ListNode* mergeSort(ListNode *beg, ListNode *end)
{
    if (beg == end) {
        beg->next = NULL;
        return beg;
    }
    
    ListNode *mid;
    int size;
    mid = beg;
    size = 0;
    while (mid != end) {
        mid = mid->next;
        size++;
    }

    size = size / 2;
    mid = beg;
    while (size > 0)
    {
        mid = mid->next;
        size--;
    }
     
    ListNode *fbeg, *fend, *sbeg, *send;
    ListNode *cur, *head;
    fbeg = beg, fend = mid;
    sbeg = mid->next, send = end;

    fbeg = mergeSort(fbeg, fend);
    sbeg = mergeSort(sbeg, send);
     
    fend = fbeg;
    while (fend->next)
        fend = fend->next;

    send = sbeg;
    while (send->next)
        send = send->next;
    
    if (fbeg->val < sbeg->val) {
        head = fbeg;
        fbeg = fbeg->next;
    } else {
        head = sbeg;
        sbeg = sbeg->next;
    }

    cur = head;

    while (fbeg != fend->next && sbeg != send->next) {
        if (fbeg->val < sbeg->val) {
            cur->next = fbeg;
            cur = fbeg;
            fbeg = fbeg->next;
        } else {
            cur->next = sbeg;
            cur = sbeg;
            sbeg = sbeg->next;
        }
    }

    if (fbeg == fend->next) {
        cur->next = sbeg;
        send->next = NULL;
    } else {
        cur->next = fbeg;
        fend->next = NULL;
    }

    return head;
}

ListNode *sortList(ListNode *head)
{
    ListNode *tail, *newhead;
    tail = head;
    while (tail->next)
       tail = tail->next; 
    newhead = mergeSort(head, tail);

    return newhead;
}

