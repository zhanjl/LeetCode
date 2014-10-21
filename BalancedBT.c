struct TreeNode {
    int     val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int MaxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;
    int nleft, nright;
    nleft = MaxDepth(root->left);
    nleft++;
    nright = MaxDepth(root->right);
    nright++;

    return (nleft > nright) ? nleft : nright;
}
bool isBalanced(struct TreeNode *root)
{
    int nleft, nright;
    if (root == NULL)
        return true;
    nleft = MaxDepth(root->left);
    nright = MaxDepth(root->right);

    if ((nleft >= (nright + 2)) || (nright >= (nleft + 2)))
        return false;
    if (isBalanced(root->left) == false)
        return false;
    if (isBalanced(root->right) == false)
        return false;
    return true;
}
