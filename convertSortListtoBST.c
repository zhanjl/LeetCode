struct ListNode {
    int              val;
    struct ListNode* next;
};

struct TreeNode {
    int              val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct ListNode* findmid(struct ListNode* start, struct ListNode* end)
{
    int count = 0;
    struct ListNode* temp;
    temp = start;
    while (temp != end)
    {
        count++;
        temp = temp->next;
    }
    count++;
    int i;
    temp = start;
    for (i = 1; i < count / 2; i++)
        temp = temp->next;
    return temp;
}

struct ListNode* findprev(struct ListNode* start, struct ListNode* end)
{
    struct ListNode* temp;
    temp = start;
    while (temp->next != end)
        temp = temp->next;
    return temp;
}

void buildBST(struct TreeNode* root, struct ListNode* ls, struct ListNode* le,
                struct ListNode* rs, struct ListNode* re)
{
    struct ListNode *mid, *left, *right;
    struct TreeNode* temp;
    if ( ls == NULL)    //ls = le = NULL
    {
        root->left = NULL;
    } 
    else 
    {
        mid = findmid(ls, le);
        temp = malloc(sizeof(struct TreeNode));
        temp->val = mid->val;
        root->left = temp;
        if (ls == mid)
            ls = left = NULL;
        else
            left = findprev(ls, mid);

        if (le == mid)
            right = le = NULL;
        else
            right = mid->next;
        buildBST(temp, ls, left, right, le);
    }

    if (rs == NULL)     //rs = re = NULL
    {
        root->right = NULL;
    }
    else
    {
        mid = findmid(rs, re);
        temp = malloc(sizeof(struct TreeNode));
        temp->val = mid->val;
        root->right = temp;

        if (rs == mid)
            rs = left = NULL;
        else
            left = findprev(rs, mid);


        if (re == mid)
            right = re = NULL;
        else
            right = mid->next;
        buildBST(temp, rs, left, right, re);
    }
    return;
}
struct TreeNode *sortedListBST(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode *mid, *end;
    struct ListNode *left, right;
    end = head;
    while (end->next)
        end = end->next;
    mid = findmid(head, end);

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = mid->val;

    if (mid == head)
        head = left = NULL;
    else
        left = findprev(head, mid);

    if (mid == end)
        right = end = NULL;
    else
        right = mid->next;

    buildBST(root, head, left, right, end);

    return root;
}
