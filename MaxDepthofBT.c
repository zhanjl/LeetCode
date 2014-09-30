/*
 * 这一题可以充分体现递归思想的优势
 */
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode** stack = NULL;
int index = 0;
int left = 0;
void push(struct TreeNode *ptr)
{
    if (left == 0)
    {
        stack = realloc(stack, 2*sizeof(struct TreeNode*));
        left = 2; 
    }
    stack[index] = ptr;
    index++;
    left--;
}
struct TreeNode* pop()
{
    if (index == 0)     //stack is empty
        return NULL;
    index--;
    left++;
    return stack[index];
}
int maxDepth(struct TreeNode *root)     //非递归解
{
    int maxdep, curdep;
    struct TreeNode *cur, *parent;
    if (root == NULL)
        return 0;
    cur = root;
    parent = NULL;
       
    maxdep = 0;
    curdep = 0;
    while (1)
    {
        if (cur->left != NULL)
        {
            push(cur);
            curdep++;
            cur = cur->left;
        }
        else if (cur->right != NULL)    //cur->left == NULL && cur->right != NULL
        {
            push(cur);
            curdep++;
            cur = cur->right;
        }
        else                            //找到叶子节点
        {
            if ((curdep+1) > maxdep)
               maxdep = curdep + 1;
            while ( (parent = pop()) != NULL)   //向上回退
            {
                if ((cur == parent->left) && (parent->right != NULL))
                {
                    push(parent);
                    cur = parent->right;
                    break;
                }
                cur = parent;
                curdep--;
            }
            if (parent == NULL)
                break;
        }
    } 
    return maxdep;
}

int recv_maxdep(struct TreeNode* root)  //递归解
{
    if (root == NULL)
        return 0;
    int left = recv_maxdep(root->left);
    int right = recv_maxdep(root->right);
    
    return left > right ? left + 1 : right + 1;
}
int main()
{
    struct TreeNode root, right1, right2, right3, right4;
    int res;
    root.left = NULL;
    root.right = &right1;

    right1.left = NULL;
    right1.right = &right2;

    right2.left = NULL;
    right2.right = &right3;

    right3.left = NULL;
    right3.right = &right4;

    right4.left = NULL;
    right4.right = NULL;
    res = recv_maxdep(&root); 
    printf("%d\n", res);
    return 0;
}
