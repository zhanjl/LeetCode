//使用队列
#define MAXNODE     100
struct TreeNode {
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void levelOrder(struct TreeNode *root)
{
    if (root == NULL)
        return;
    struct TreeNode *queue[100];
    int prev, cur, next;
    queue[0] = root;
    prev = 0;
    cur = next = 1;

    while (1)
    {
        while (prev != cur)
        {
            printf("%d ", queue[prev]->val);
            if (queue[prev]->left)
                queue[next++] = queue[prev]->left;
            if (queue[prev]->right)
                queue[next++] = queue[prev]->right;
        }
        printf("\n");
        if (cur == next)
            break;
        cur = next;
    }
}
