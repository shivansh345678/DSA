#include <iostream>
using namespace std;
class node
{
public:
    int data = 0;
    node *nxt = NULL;
};
node *ins_ert(node *ptr, int val)
{
    node *temp = new node;
    temp->data = val;
    temp->nxt = NULL;
    if (ptr != NULL)
    {
        ptr->nxt = temp;
    }
    ptr = temp;
    return ptr;
}
node *del_ete(node *fr)
{
    if (fr == NULL)
    {
        cout << "queue is empty" << endl;
        return NULL;
    }
    else
    {
        fr = fr->nxt;
        return fr;
    }
}
void print(node *fr)
{
    node *t1 = fr;
    while (t1 != NULL)
    {
        printf("%d ", t1->data);
        t1 = t1->nxt;
    }
    printf("\n");
}
int main()
{
    cout << "Enter the number of elements" << endl;
    int n, a;
    scanf("%d", &n);
    node *fr = NULL, *bk = NULL;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        if (i == 1)
        {
            bk = ins_ert(bk, a);
            fr = bk;
        }
        else
        {
            bk = ins_ert(bk, a);
        }
    }
    cout << "Poping the elements" << endl;
    print(fr);
    return 0;
}
