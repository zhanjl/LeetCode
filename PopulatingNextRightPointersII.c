struct TreeLinkNode {
    int     val;
    struct TreeLinkNode *left, *right, *next;
};

void connect (struct TreeLinkNode *root)
{
    struct TreeLinkNode *savecur, *cur, *next;
    if (root == NULL)
        return;
    savecur = root;
    while (1) {
        cur = savecur;
        while (cur) {
            next = cur->next;
            
            while (next) {
                if ( next->left || next->right)
                    break;
                next = next->next;
            }
            if (cur->left && cur->right) {
                cur->left->next = cur->right;
                if (next != NULL) {
                    if (next->left)
                        cur->right->next = next->left;
                    else if (next->right)
                        cur->right->next = next->right;
                }
            } else if (cur->left) {
                if (next != NULL) {
                    if (next->left)
                        cur->left->next = next->left;
                    else if (next->right)
                        cur->left->next = next->right;
                }
            } else if (cur->right) {
                if (next != NULL) {
                    if (next->left)
                        cur->right->next = next->left;
                    else if (next->right)
                        cur->right->next = next->right;
                }
            }
            cur = next;
        }

        while (savecur) {
            if (savecur->left || savecur->right)
                break;
            savecur = savecur->next;
        }
        if (savecur == NULL)
            break;
        if (savecur->left)
            savecur = savecur->left;
        else
            savecur = savecur->right;
    }
    return;
}

//精简版
void connect1(struct TreeLinkNode *root)
{
    //head是下一层的第一个节点,head是下一层从左到右第一个要求next的节点
    struct TreeLinkNode *cur, *prev, *head;
    
    cur = root;
    prev = head = NULL;

    while (cur) {
        while (cur) {
            if (cur->left) {
                if (prev == NULL) {
                    head = cur->left;
                } else {
                    prev->next = cur->left;
                }
                prev = cur->left;
            }
            if (cur->right) {
                if (prev == NULL) {
                    head = cur->right;
                } else {
                    prev->next = cur->right;
                }
                prev = cur->right;   
            }
            cur = cur->next;
        }
        cur = head;
        prev = NULL;
        head = NULL;
    }
}
