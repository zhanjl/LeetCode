struct TreeNode {
    int     val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//递归解法
bool isSame(struct TreeNode *left, struct TreeNode *right)
{
    if (!left && !right)
        return true;
    else if (!left && right)
        return false;
    else if (left && !right)
        return false;

    if (left->val != right->val)
        return false;
    if (!isSame(left->left, right->right))
        return false;
    if (!isSame(left->right, right->left))
        return false;
    return true;
}

bool isSymmetric(struct TreeNode *root)
{
    if (root == NULL)
        return true;
    return isSame(root->left, root->right);
}


//使用C++的迭代解法
bool isSame(struct TreeNode *root)
{
    if (root == NULL)
        return true;
    stack<TreeNode*> left;
    stack<TreeNode*> right;

    TreeNode *n1, *n2;

    left.push(root->left);
    right.push(root->right);

    while (!left.empty() && !right.empty())
    {
        n1 = left.top();
        n2 = right.top();

        left.pop();
        right.pop();

        if (!n1 && !n2)
            continue;
        else if (!n1 && n2)
            return false;
        else if (n1 && !n2)
            return false;

        if (n1->val != n2->val)
            return false;

        left.push(n1->left);
        right.push(n2->right);

        left.push(n1->right);
        right.push(n2->left);
    }
    return true;
}
