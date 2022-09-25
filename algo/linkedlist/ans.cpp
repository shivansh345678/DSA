#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *nxt = NULL;
};
node *insert(node *head, int val)
{
    node *temp = new node;
    temp->data = val;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *ptr = head;
        while (ptr->nxt != NULL)
        {
            ptr = ptr->nxt;
        }
        ptr->nxt = temp;
    }
    return head;
}
node *conc(node *l1, node *l2)
{
    node *temp, *p1 = l1, *p2 = l2, *p3;
    if (l1 != NULL && l2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3 = p1;
            p1 = p1->nxt;
            p3->nxt = NULL;
        }
        else
        {
            p3 = p2;
            p2 = p2->nxt;
            p3->nxt = NULL;
        }
        temp = p3;
        while (p2 != NULL && p1 != NULL)
        {
            node *temp1 = new node;
            if (p1->data < p2->data)
            {
                temp1->data = p1->data;
                p1 = p1->nxt;
                p3->nxt = temp1;
                p3 = temp1;
            }
            else
            {
                temp1->data = p2->data;
                p2 = p2->nxt;
                p3->nxt = temp1;
                p3 = temp1;
            }
        }
        while (p1 != NULL)
        {
            node *temp1 = new node;
            temp1->data = p1->data;
            p1 = p1->nxt;
            p3->nxt = temp1;
            p3 = temp1;
        }
        while (p2 != NULL)
        {
            node *temp1 = new node;
            temp1->data = p2->data;
            p2 = p2->nxt;
            p3->nxt = temp1;
            p3 = temp1;
        }
        return temp;
    }
    else
    {
        if (l1 != NULL)
        {
            return l1;
        }
        else
        {
            return l2;
        }
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->nxt;
    }
    printf("\n");
}
int main()
{
    int n, m, a;
    cout << "Enter the number of elements in 1st and 2nd linked list" << endl;
    scanf("%d %d", &n, &m);
    node *l1 = NULL, *l2 = NULL, *l3 = NULL;
    cout << "Enter the elements of 1st list" << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        l1 = insert(l1, a);
    }
    cout << "Enter the elements of 2nd list" << endl;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a);
        l2 = insert(l2, a);
    }
    l3 = conc(l1, l2);
    cout << "The new list is" << endl;
    print(l3);
    return 0;
}







