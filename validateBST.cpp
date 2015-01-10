//中序遍历，遍历结果应该为严格升序
//否则，则不是一个有效的BST
TreeNode *last;
bool isValidBST(TreeNode *root)
{
     if (root == NULL)
         return true;
     if (isValidBST(root->left) == false)
         return false;
     if (last && last->val >= root->val)
         return false;
     last = root;

     return isValidBST(root->right);
}
