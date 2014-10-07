
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int MaxDepth(struct TreeNode* root)  //递归解
{
    if (root == NULL)
        return 0;
    int left = recv_maxdep(root->left);
    int right = recv_maxdep(root->right);
    return left > right ? left + 1 : right + 1;
}
