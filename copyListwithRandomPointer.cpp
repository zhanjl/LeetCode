RandomListNode *copyRandomList(RandomListNode *head)
{
    if (head == NULL)
        return NULL;
    map<RandomListNode*, int>   first;
    map<int, RandomListNode*>   second;
     
    RandomListNode *res, *first_cur, *sec_prev, *sec_cur;
    int cnt = 1;
    //初始化第一个节点
    res = new RandomListNode(head->label);

    first[head] = cnt;
    second[cnt] = res;
    cnt++;

    first_cur = head->next;
    sec_prev = res;

    while (first_cur) {
        sec_cur = new RandomListNode(first_cur->label);
        sec_prev->next = sec_cur;

        first[first_cur] = cnt;
        second[cnt] = sec_cur;
        cnt++;

        first_cur = first_cur->next;
        sec_prev = sec_cur;
    }

    first_cur = head;
    sec_cur = res;
    while (first_cur) {
        if (first_cur->random == NULL) {
            sec_cur->random = NULL;
        } else {
            sec_cur->random = second[first[first_cur->random]];
        }

        first_cur = first_cur->next;
        sec_cur = sec_cur->next;
    }

    return res;
}
