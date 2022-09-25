#include <iostream>
#include <cstdlib>
using namespace std;
class TreeNode
{
public:
    int val = 0;
    TreeNode *lft = NULL;
    TreeNode *rgt = NULL;
};
TreeNode *insert(TreeNode *add, int vl, int p)
{
    TreeNode *temp = new TreeNode;
    temp->val = vl;
    temp->lft = NULL;
    temp->rgt = NULL;
    if (add != NULL)
    {
        if (p == 0)
        {
            add->lft = temp;
        }
        else
        {
            add->rgt = temp;
        }
    }
    return temp;
}
void solve(TreeNode *root, TreeNode *st[], int ans[], int *g, int *u)
{
    TreeNode *temp = root;
    while (temp != NULL)
    {
        (*g)++;
        // printf("%d",(*u));
        ans[(*g)] = temp->val;
        if (temp->rgt != NULL)
        {
            (*u)++;
            st[(*u)] = temp->rgt;
        }
        temp = temp->lft;
    }
}
void preorder(TreeNode *root, int n, int ans[])
{
    TreeNode *ptr = root;
    TreeNode *st[n + 3];
    int u = 0, g = 0;
    while (ptr != NULL)
    {
        // printf("%d %d\n", u, g);
        solve(ptr, st, ans, &g, &u);
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
    for (int i = 1; i <= g; i++)
    {
        printf("%d ", ans[i]);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements in Binary tree" << endl;
    scanf("%d", &n);
    int arr[n + 3], ans[n + 3];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int s = 1;
    TreeNode *root = NULL, *stc[n + 3];
    stc[s] = insert(root, arr[s], 0);
    root = stc[s];
    while (2 * s <= n)
    {
        // printf("%d %d", stc[s],root);
        if (2 * s <= n)
        {
            stc[2 * s] = insert(stc[s], arr[2 * s], 0);
        }
        if (2 * s + 1 <= n)
        {
            stc[2 * s + 1] = insert(stc[s], arr[2 * s + 1], 1);
        }
        s++;
    }
    cout<<"Preorder of binary tree"<<endl;
    preorder(root, n, ans);
    return 0;
}
