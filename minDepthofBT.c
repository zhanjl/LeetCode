
struct TreeNode {
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int finddepth(struct TreeNode *root, int curdep)
{
    int left, right;
    left = right = 0;
    curdep++;
    if (root->left == NULL && root->right == NULL)
        return curdep;        
    if (root->left)
        left = finddepth(root->left, curdep);
    if (root->right)
        right = finddepth(root->right, curdep);
    if (left == 0)
        return right;
    else if (right == 0)
        return left;
    return left < right ? left : right;
}

int minDepth(struct TreeNode *root)
{
    int res;
    if (root == NULL)
        return 0;
    res = finddepth(root, 0);
    return res;
}
