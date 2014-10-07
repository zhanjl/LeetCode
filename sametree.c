struct TreeNode {
    int val;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if ((p == NULL) || (q == NULL))
        return p == q;
    return (p->val == q->val) && isSameTree(p->lchild, q->lchild) &&
                                isSameTree(p->rchild, q->rchild);
}

