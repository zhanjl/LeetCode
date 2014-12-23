int preindex = 0;

void findboundary(vector<int> &preorder, vector<int> &inorder, int beg, int end, int val,
                    int *lb, int *le, int *rb, int *re)
{
    int index;
    for (index = beg; index <= end; index++)
    {
        if (inorder[index] == val)
            break;
    }
    int nlb, nle, nrb, nre;
     
    nlb = lbeg;
    nle = index - 1;
    nrb = index + 1;
    nre = lend;

    if (nlb > nle)
        nlb = nle = -1;
    if (nrb > nre)
        nrb = nre = -1;

    *lb = nlb;
    *le = nle;
    *rb = nrb;
    *re = nre;
}

void realwork(TreeNode *root, vector<int> &preorder, vector<int> &inorder,
                int lbeg, int lend, int rbeg, int rend)
{
    int nlb, nle, nrb nre;
    TreeNode *temp;
    if (lbeg == -1)
    {
        root->left = NULL;
    }
    else 
    {
        temp = new TreeNode(preorder[preindex++]);
        root->left = temp;
        findboundary(preorder, inorder, lbeg, lend, temp->val, &nlb, &nle, &nrb, &nre);
        realwork(temp, preorder, inorder, nlb, nle, nrb, nre);
    }
    if (rbeg == -1)
    {
        root->right = NULL;
    }
    else 
    {
        temp = new TreeNode(preorder[preindex++]);
        root->right = temp;
        findboundary(preorder, inorder, rbeg, rend, temp->val, &nlb, &nle, &nrb, &nre);
        realwork(temp, preorder, inorder, nlb, nle, nrb, nre);
    }
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    if (preorder.size() == 0)
       return NULL;
    int nlb, nle, nrb, nre;
    TreeNode *root; 
    root = new TreeNode(preorder[preindex++]);
    findboundary(preorder, inorder, 0, inorder.size() - 1, root->val, &nlb, &nle, &nrb, &nre);
    realwork(root, preorder, inorder, nlb, nle, nrb, nre);

    return root;
}
