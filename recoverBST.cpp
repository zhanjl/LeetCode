//prev记录中序遍历的前一个节点
TreeNode *prev = NULL;
//如果错误的是中序遍历后两个相邻的节点，则最终结果mis2为空
//此时mis2的值应该为mis1的中序遍历的下一个节点
//cur就是记录该值
TreeNode *cur;  
void inOrder(TreeNode *root, TreeNode **mis1, TreeNode **mis2)
{
    if (root == NULL)
        return;
    inOrder(root->left, mis1, mis2);
    if (prev && root->val < prev->val)
    {
        if (*mis1 == NULL)
        {
            *mis1 = prev;
            cur = root;
        }
        else
            *mis2 = root;
    }
    prev = root;
    inOrder(root->right, mis1, mis2);
}

void recoverTree(TreeNode *root)
{
    int temp;
    TreeNode *mis1, *mis2;  //mis1和mis2是错误的两个节点
    mis1 = mis2 = NULL;
    inOrder(root, &mis1, &mis2);
    if (mis2 == NULL)
        mis2 = cur;
    temp = mis1->val;
    mis1->val = mis2->val;
    mis2->val = temp;
}
