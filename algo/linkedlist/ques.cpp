#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *front = NULL;
    node *back = NULL;
};
node *insert(node *head, node *tail, int val, int p)
{
    node *temp = new node;
    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        return head;
    }
    else
    {
        if (p == 0)
        {
            head->back = temp;
            temp->front = head;
            head = temp;
            return head;
        }
        else
        {
            tail->front = temp;
            temp->back = tail;
            tail=temp;
            return tail;
        }
    }
}
void print(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->front;
    }
    printf("\n");
}
int main()
{
    node *head = NULL, *tail = NULL;
    int n, c = 1, a, b;
    cout << "Enter the number of stations" << endl;
    cin >> n;
    cout << "Enter the station number and 0 if it inseted in front and 1 if inserted in back" << endl;
    while (c <= n)
    {
        scanf("%d %d", &a, &b);
        if (c == 1)
        {
            head = insert(head, tail, a, b);
            tail = head;
        }
        else
        {
            if (b == 0)
            {
                head = insert(head, tail, a, b);
            }
            else
            {
                tail = insert(head, tail, a, b);
            }
        }
        c++;
    }
    //printf("%d %d ",sizeof(node),sizeof(int));
    print(head);
    return 0;
}
