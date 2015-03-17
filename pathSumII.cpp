//深度优先搜索
void depth_first(TreeNode *root, int sum, vector<int> &path, vector<vector<int> > &result)
{
    if (root == NULL)
        return;
    path.push_back(root->value);
    sum -= root->value;

    if (sum == 0) {
        if (root->left == NULL && root->right == NULL) {
            result.push_back(path);
        }
    }
    
    depth_first(root->left, sum, path, result);
    depth_first(root->right, sum, path, result);
    path.pop_back();
    return;
}

vector<vector<int> > pathSum(TreeNode *root, int sum)
{
    vector<vector<int> >    result;
    vector<int>             path;
    depth_first(root, sum, path, result);
    return result;
}

