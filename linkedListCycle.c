#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//判断是否有环
int hasCycle(struct ListNode *head)
{
    if (head == NULL)
        return 0;
    struct ListNode *front, *behind;
    behind = head;
    front = head->next;
    while (front && front->next)
    {
        if (front == behind)
            break;
        front = front->next->next;
        behind = behind->next; 
    }
    return  !(front == NULL || front->next == NULL);
}

//找到环的入口点
struct ListNode* findEntrance(struct ListNode *head)
{
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    if ( fast == NULL || fast->next == NULL)
        return NULL;
    fast = head;
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{

    return 0;
}
