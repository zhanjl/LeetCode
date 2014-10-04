struct TreeNode {
    int val;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    bool lchild, rchild;
    
    if ((p == NULL) && (q == NULL))
        return true;
    else if ((p != NULL) && (q != NULL))
    {
        if (p->val != q->val)
            return false;
        lchild = isSameTree(p->lchild, q->lchild);
        if (lchild == false)
            return false;
        rchild = isSameTree(p->rchild, q->rchild);
        if (rchild == false)
            return false;
        return true;
    }
    else
        return false;
}

