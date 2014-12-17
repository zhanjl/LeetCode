
//算法一：思路很简单，但是实现的太复杂了。。。。。
struct TreeNode {
    int         val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void construct(struct TreeNode *root, vector<int> &inorder, int inlbeg, int inlend, int inrbeg, 
                int inrend, vector<int> &postorder, int polbeg, int polend, int porbeg, int porend)
{
    int index;

    int ninrbeg, ninrend, nporbeg, nporend;
    ninrbeg = inrbeg;
    ninrend = inrend;
    nporbeg = porbeg;
    nporend = porend;
    if (inlbeg == -1)   //左子树为空
    {
        root->left = NULL;
    }
    else
    {
        struct TreeNode *left = new (struct TreeNode);
        left->val = postorder[polend];
        root->left = left;
        for (index = inlbeg; index <= inlend; index++)
        {
            if (inorder[index] == postorder[polend])
                break;
        } 
        
        //求出新的inlbeg, inlend, inrbeg, inrend;
        
        inrbeg = index + 1;
        inrend = inlend;
         
        inlbeg = inlbeg;
        inlend = index - 1;

        if (inrbeg > inrend)
            inrbeg = inrend = -1;

        if (inlbeg > inlend)
            inlbeg = inlend = -1;

        //求出post新的lbeg, lend, rbeg, rend 
        
        polend--;
        porend = polend;
        
        polend = polbeg + inlend - inlbeg;
        porbeg = polend + 1;
        
        if (inlbeg == -1)
            porbeg = polbeg;
        if (inrbeg == -1)
            polend = porend;

        construct(left, inorder, inlbeg, inlend, inrbeg, inrend, postorder, 
                polbeg, polend, porbeg, porend);
    }

    inrbeg = ninrbeg;
    inrend = ninrend;
    porbeg = nporbeg;
    porend = nporend;
    if (inrbeg == -1)   //右子树为空
    {
        root->right = NULL;
    }
    else
    {
        struct TreeNode *right = new(struct TreeNode);
        right->val = postorder[porend];
        root->right = right;

        for (index = inrbeg; index <= inrend; index++)
        {
            if (inorder[index] == postorder[porend])
                break;
        } 
        
        inlbeg = inrbeg;
        inlend = index - 1;
        
        inrbeg = index + 1;
        inrend = inrend;
         

        if (inrbeg > inrend)
            inrbeg = inrend = -1;

        if (inlbeg > inlend)
            inlbeg = inlend = -1;


        porend--;
        polbeg = porbeg; 

        polend = polbeg + inlend - inlbeg;
        porbeg = polend + 1;
        
        if (inlbeg == -1)
            porbeg = polbeg;
        if (inrbeg == -1)
            polend = porend;

        construct(right, inorder, inlbeg, inlend, inrbeg, inrend, postorder, 
                polbeg, polend, porbeg, porend);

    }
    return;
}

struct TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    if (inorder.size() == 0)
        return NULL;
    struct TreeNode *root = new (struct TreeNode);   
    int insize, postsize;
    insize = inorder.size() - 1;
    postsize = postorder.size() - 1;

    root->val = postorder[postsize];

    int inlbeg, inlend, inrbeg, inrend;
    int polbeg, polend, porbeg, porend;

    int index;
    for (index = 0; index <= insize; index++)
    {
        if (inorder[index] == postorder[postsize])
            break;
    }
    postsize--;
    inlbeg = 0;
    inlend = index - 1;

    inrbeg = index + 1;
    inrend = insize;

    if (inlbeg > inlend)
        inlbeg = inlend = -1;
    if (inrbeg > inrend)
        inrbeg = inrend = -1;

    polbeg = 0;
    porend = postsize;

    polend = polbeg + inlend - inlbeg;
    porbeg = polend + 1;

    if (inlbeg == -1)
        porbeg = 0;
    if (inrbeg == -1)
        polend = postsize;
    construct(root, inorder, inlbeg, inlend, inrbeg, inrend, postorder, 
            polbeg, polend, porbeg, porend);

    return root;
}

