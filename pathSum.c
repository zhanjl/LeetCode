//就是深度优先搜索

struct TreeNode {
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode *root, int sum)
{
    if (root == NULL)
        return false;
    
    if (root->left == NULL && root->right == NULL)
    {
        if (root->val == sum)
            return true;
        return false;
    }

    if (hasPathSum(root->left, sum - root->val))
        return true;

    if (hasPathSum(root->right, sum - root->val))
        return true;
    return false;
}
