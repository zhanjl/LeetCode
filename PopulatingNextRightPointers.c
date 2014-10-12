
struct TreeLinkNode {
    int     val;
    struct TreeLinkNode *left, *right, *next;
};

void connect(struct TreeLinkNode *root)
{
    struct TreeLinkNode *parent, *cur, *next;
    struct TreeLinkNode *saveparent, *savecur;
    if (root == NULL)
       return;
    saveparent = root;
    savecur = root->left; 
    while (savecur) {
        parent = saveparent;
        cur = savecur;
        while (1) {
            if (cur == parent->left) {
                next = parent->right;
            } else {
                parent = parent->next;
                if (parent == NULL)
                    break;
                next = parent->left;
            }
            cur->next = next;
            cur = next;
        }
        saveparent = savecur;
        savecur = savecur->left;
    }    
    return;
}

//更精简的版本
void connect1(struct TreeLinkNode *root)
{
    TreeLinkNode *cur, *savecur;
    if (root == NULL)
        return;
    savecur = root;
    while (savecur->left) {
        cur = savecur;
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next)
                cur->right->next = cur->next->left;
            cur = cur->next;
        }
        savecur = savecur->left;
    }
}
