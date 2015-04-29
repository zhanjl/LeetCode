void built_heap(vector<ListNode*> &heap, int heapsize)
{
    for (int i = 2; i <= heapsize; i++) {
        int j = i;
        while (j > 1) {
            if (heap[j/2]->val <= heap[j]->val)
               break;
            ListNode* temp;
            temp = heap[j];
            heap[j] = heap[j/2];
            heap[j/2] = temp; 
            j = j / 2;
        }
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{ 

    ListNode *result = NULL;
    ListNode *cur;
    vector<ListNode*> heap;
    int heapsize = 0; 
    heap.push_back(0);
    for (vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); it++)
    {
        if (*it != NULL) {
            heap.push_back(*it);
            heapsize++;
        }
    }
    
    if (heapsize == 0)
        return NULL;
    //建立一个小顶堆
    built_heap(heap, heapsize);

    result = heap[1];
    cur = NULL;
    while (heapsize > 0) {
        if (cur == NULL) {
            cur = heap[1];
        } else {
            cur->next = heap[1];
            cur = cur->next;
        }
        if (cur->next) {
            heap[1] = cur->next;
        } else {
            heap[1] = heap[heapsize];
            heapsize--;
        }

        //维护这个小顶堆
        int i = 1;
        int j;
        while ((2*i) <= heapsize) {
            if ((2*i+1) > heapsize) {
                j = 2 * i;
            } else {
                if (heap[2*i]->val < heap[2*i+1]->val)
                    j = 2 * i;
                else
                    j = 2 * i + 1;
            }

            if (heap[i]->val < heap[j]->val)
                break;
            
            ListNode* temp;
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
        }
    }
    return result;
}

