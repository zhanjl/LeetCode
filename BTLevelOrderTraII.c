//其实和Binary Tree Level Order Traversal完全没区别，
//把前一题求出的结果反转就OK
//下面是C++代码，其实就是DFS
struct TreeNode {
    int             val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//深搜递归的思想很值得借鉴
vector<vector<int> > res;
void DFS(struct TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (res.size() == level)
        res.push_back(vector<int>());
    res[level].push_back(root->val);
    DFS(root->left, level+1)
    DFS(root->right, level+1)
}

vector<vector<int> > levelOrderBottom(struct TreeNode *root)
{
    DFS(root, 0);
    return vector<vector<int> >(res.rbegin(), res.rend());
}
