struct TreeNode {
    int     val;
    TreeNode *left;
    TreeNode *right;
};

void postorderTraversal(TreeNode *root)
{
    struct TreeNode* stack[100];    //假设树的节点不超过100个
    int top = 0;
    struct TreeNode *cur, *parent;
    if (root == NULL)
        return;
    cur = root;
    while (1) {
        while (cur) {
            stack[top++] = cur;
            cur = cur->left;
        }
        parent = stack[top-1];
        cur = parent->right;
        if (cur == NULL) {   //如果左右孩子都为空
            cur = stack[--top];     //出栈
            printf("%d\n", cur->val);
            while (top != 0) {  //如果当前节点是父节点的右孩子，也要输出父节点
                parent = stack[top-1];
                if (cur == parent->left)
                {
                    cur = parent->right;
                    break;
                }
                cur = stack[--top];
                printf("%d\n", cur->val);
            }
            if (top == 0)
                break;
        }
    }
}

//下面的解题思路很精妙
//后序遍历的顺序是left-right-root
//我们先按root-right-left顺序输出，然后再反转。
//c++代码
/*
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode*> stack;
    TreeNode *temp;
    if (root == NULL)
        return result;
    stack.push(root);
    while (!stack.empty()) {
        temp = stack.top();
        stack.pop();
        result.push_back(temp->val);
        if (temp->left) stack.push(temp->left);
        if (temp->right) stack.push(temp->right);
    }
    reverse(result.begin(), result.end());
    return result;
}
 
 */
