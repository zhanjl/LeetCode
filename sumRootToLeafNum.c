
struct TreeNode {
    int                 val;
    struct TreeNode*    left;
    struct TreeNode*    right;
};

void curSum(struct TreeNode *root, int sum, int *res)
{
    int lsum, rsum;
    lsum = rsum = sum;
    if (root->left == NULL && root->right == NULL)
    {
        sum = sum * 10 + root->val;
        *res += sum;
        return;
    }
    //这样写是有错误的因为root->left的sum和root->right的不同了
    if (root->left)
    {
        lsum = lsum * 10 + root->val;
        curSum(root->left, lsum, res);
    }
    if (root->right)
    {
        rsum = rsum * 10 + root->val;
        curSum(root->right, rsum, res);
    }
}
int sumNumbers(struct TreeNode *root)
{
    int res;
    res = 0;
    curSum(root, 0, &res);
    return res;
}
