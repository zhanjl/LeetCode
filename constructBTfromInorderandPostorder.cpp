//精巧的算法，目前理解不了

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0)
        return NULL;
    TreeNode *p;
    TreeNode *root;
    stack<TreeNode*> stn;

    root = new TreeNode(postorder.back());
    stn.push(root);
    postorder.pop_back();

    while (true)
    {
        if (inorder.back() == stn.top()->val)
        {
            p = stn.top();
            stn.pop();
            inorder.pop_back();
            if (inorder.size() == 0)
                break;
            if (stn.size() && inorder.back() == stn.top()->val)
                continue;
            p->left = new TreeNode(postorder.back());
            postorder.pop_back();
            stn.push(p->left);
        }
        else
        {
            p = new TreeNode(postorder.back());
            postorder.pop_back();
            stn.top()->right = p;
            stn.push(p);
        }
    }

    return root;
}
