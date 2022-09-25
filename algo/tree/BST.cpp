#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}
class node
{
public:
    int hgt = 1, val;
    node *lft = NULL;
    node *rgt = NULL;
};
int height(node *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        return ptr->hgt;
    }
}
node *right(node *ptr)
{
    node *temp = ptr->lft, *p1 = temp->rgt;
    ptr->lft = p1;
    temp->rgt = ptr;
    ptr->hgt = max(height(ptr->lft), height(ptr->rgt)) + 1;
    temp->hgt = max(height(temp->lft), height(temp->rgt)) + 1;
    return temp;
}
node *left(node *ptr)
{
    node *temp = ptr->rgt, *p1 = temp->lft;
    ptr->rgt = p1;
    temp->lft = ptr;
    ptr->hgt = max(height(ptr->lft), height(ptr->rgt)) + 1;
    temp->hgt = max(height(temp->lft), height(temp->rgt)) + 1;
    return temp;
}
node *insert(node *root, int a, int n)
{
    node *temp = new node;
    temp->val = a;
    if (root == NULL)
    {
        root = new node;
        root->val = a;
    }
    else
    {
        node *arr[(int)log(n) + 8], *ptr = root, *p1;
        int u = 0;
        while (1)
        {
            u++;
            arr[u] = ptr;
            if (ptr->val < a)
            {
                if (ptr->rgt == NULL)
                {
                    ptr->rgt = temp;
                    u++;
                    arr[u] = temp;
                    break;
                }
                ptr = ptr->rgt;
            }
            else
            {
                if (ptr->lft == NULL)
                {
                    ptr->lft = temp;
                    u++;
                    arr[u] = temp;
                    break;
                }
                ptr = ptr->lft;
            }
        }
        for (int i = u; i >= 1; i--)
        {
            p1 = arr[i];
            // printf("%d/%d%d ", p1->val, i,height(p1->rgt));
            if (height(p1->lft) - height(p1->rgt) >= 2 || height(p1->lft) - height(p1->rgt) <= -2)
            {
                if (height(p1->lft) - height(p1->rgt) >= 2)
                {
                    if (i == 1)
                    {
                        if (p1->lft->lft == arr[i + 2])
                        {
                            root = right(p1);
                        }
                        else
                        {
                            p1->lft = left(p1->lft);
                            root = right(p1);
                        }
                    }
                    else
                    {
                        if (p1->lft->lft == arr[i + 2])
                        {
                            if (arr[i - 1]->rgt == p1)
                            {
                                arr[i - 1]->rgt = right(p1);
                            }
                            else
                            {
                                arr[i - 1]->lft = right(p1);
                            }
                        }
                        else
                        {
                            p1->lft = left(p1->lft);
                            if (arr[i - 1]->rgt == p1)
                            {
                                arr[i - 1]->rgt = right(p1);
                            }
                            else
                            {
                                arr[i - 1]->lft = right(p1);
                            }
                        }
                    }
                }
                else
                {
                    // printf("%d %d*/\n", p1->val, i);
                    if (i == 1)
                    {
                        if (p1->rgt->rgt == arr[i + 2])
                        {
                            root = left(p1);
                        }
                        else
                        {
                            p1->rgt = right(p1->rgt);
                            root = left(p1);
                        }
                    }
                    else
                    {
                        if (p1->rgt->rgt == arr[i + 2])
                        {
                            if (arr[i - 1]->rgt == p1)
                            {
                                arr[i - 1]->rgt = left(p1);
                                // printf("%d**\n", arr[i - 1]->rgt->val);
                            }
                            else
                            {
                                arr[i - 1]->lft = left(p1);
                            }
                        }
                        else
                        {
                            p1->rgt = right(p1->rgt);
                            if (arr[i - 1]->rgt == p1)
                            {
                                arr[i - 1]->rgt = left(p1);
                            }
                            else
                            {
                                arr[i - 1]->lft = left(p1);
                            }
                        }
                    }
                }
                // printf("\n%d\n", root->val);
            }
            else
            {
                p1->hgt = max(height(p1->lft), height(p1->rgt)) + 1;
            }
        }
    }
    return root;
}
void solve(node *root, node *st[], int ans[], int *g, int *u)
{
    node *temp = root;
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
void preorder(node *root, int n)
{
    int ans[n + 3];
    node *ptr = root;
    node *st[n + 3];
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
    node *root = NULL;
    int n, a;
    cout << "Enter the  number of elements in the BST" << endl;
    scanf("%d", &n);
    cout << "Enter the elements in the BST" << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        root = insert(root, a, n);
    }
    cout << "Preorder of BST" << endl;
    preorder(root, n);
    return 0;
}
