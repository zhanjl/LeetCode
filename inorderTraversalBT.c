//二叉树的先序和中序遍历，递归和迭代代码
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d\n", root->val);
    inorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d\n", root->val);
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

//迭代版本
void inorderTraversaliter(struct TreeNode *root)
{
    struct TreeNode *stack[100];    //假设树的节点不超过100个
    int top = 0;
    struct TreeNode *child, *temp;

    temp = root;
    while (1)
    {
        while (temp)
        {
            stack[top++] = temp;
            temp = temp->left;
        }
        if (top == 0)
            break;
        temp = stack[--top];
        printf("%d\n", temp->val);
        temp = temp->right;
    }
}

void postorderTraversaliter(struct TreeNode *root)
{
    struct TreeNode *stack[100];    //假设树的节点不超过100个
    int top = 0;
    struct TreeNode *child, *temp;

    temp = root;
    while (1)
    {
        while (temp)
        {
            stack[top++] = temp;
            printf("%d\n", temp->val);
            temp = temp->left;
        }
        if (top == 0)
            break;
        temp = stack[--top];
        temp = temp->right;
    }
}

