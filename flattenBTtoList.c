
struct TreeNode {
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode *root)
{
    struct TreeNode *temp, *bottom;
    if (root == NULL)
        return;
    flatten(root->left);
    temp = root->right;
    if (root->left)
    {
        root->right = root->left;
        root->left = NULL;
        bottom = root->right;

        while (boot->right)
            boot = boot->right;
        boot->right = temp;
    }
    flatten(temp);
}
