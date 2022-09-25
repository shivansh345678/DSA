#include <iostream>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
    int val = 0;
    node *lft = NULL;
    node *rgt = NULL;
};
class Solution
{
public:
    void solve1(TreeNode *root, int *u, int *p, TreeNode *st[], int ans[]);
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *st[102];
        int u = 0, ans[102], p = 0;
        vector<int> AB;
        TreeNode *ptr = root;
        while (ptr != NULL)
        {
            solve1(ptr, &u, &p, st, ans);
            if (u != 0)
            {
                ptr = st[u];
                u--;
            }
            else
            {
                ptr = NULL;
            }
        }
        for (int i = 1; i <= p; i++)
        {
            AB.push_back(ans[i]);
        }
        return AB;
    }
};
void Solution ::solve1(TreeNode *root, int *u, int *p, TreeNode *st[], int ans[])
{
    TreeNode *ptr = root;
    while (ptr != NULL)
    {
        (*p)++;
        ans[(*p)] = ptr->val;
        if (ptr->right != NULL)
        {
            (*u)++;
            st[(*u)] = ptr->right;
        }
        ptr = ptr->left;
    }
}
int main()
{
    return 0;
}