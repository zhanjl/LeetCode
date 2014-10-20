struct TreeNode {
    int     val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void buildBST(int A[], int l, int u, struct TreeNode **root)
{
    if (l > u) {
        *root = NULL;
        return;
    }
    int mid;
    struct TreeNode *temp;
    mid = (l + u) / 2;
    temp = malloc(sizeof(struct TreeNode));
    temp->val = A[mid];
    *root = temp;
    buildBST(A, l, mid-1, &temp->left);
    buildBST(A, mid+1, u, &temp->right);
}
struct TreeNode *sortedArrayToBST(int A[], int n)
{
     struct TreeNode* root;
     buildBST(A, 0, n-1, &root);
     return root;
}

