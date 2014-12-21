//算法一，利用队列
vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
    queue<TreeNode*> que;
     
    vector<vector<int> > res;
    if (root == NULL)
        return res;
    bool reverse;
    TreeNode *temp; 

    que.push(root); 
    que.push(NULL);
    reverse = false;
     
    while (!que.empty())
    {
        vector<int> cur;
        stack<TreeNode*> stk;
        
        temp = que.front();
        que.pop();

        while (temp != NULL)
        {
            if (reverse)
                stk.push(temp);
            else
                cur.push_back(temp->val);
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
            temp = que.front();
            que.pop();
        }
        if (!que.empty())
            que.push(NULL);
        if (reverse)
        {
            while (!stk.empty())
            {
                temp = stk.top();
                stk.pop();
                cur.push_back(temp->val);
            }
            reverse = false;
        }
        else
            reverse = true;
        res.push_back(cur);
    }
    
    return res; 
}


//算法二，利用递归
vector<vector<int> > result;

vector<int> *getrow(int level)
{
    if (level == result.size())
    {
        vector<int> temp;
        result.push_back(temp);
    }

    return &result[level];
}

void traver(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    vector<int> *temp = getrow(level);
    temp->push_back(root->val);
    traver(root->left, level+1);
    traver(root->right, level+1);
}

vector<vector<int> > zigzagLevelOrder(TreeNode *root)
{
    traver(root, 0);
    for (int i = 1; i < result.size(); i += 2)
        reverse(result[i].begin(), result[i].end());

    return result;
}
