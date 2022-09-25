// AUTHOR - SHIVANSH
#include <iostream>
using namespace std;
template <class T = int>
class node
{
public:
    T data;
    node *pt = NULL;
};
template <typename T = int>
node<T> *insert(node<T> *head, T val)
{
    node<T> *temp = new node<T>;
    temp->data = val;
    temp->pt = head;
    return temp;
}
template <typename T = int>
node<T> *remove(node<T> *head, T val)
{
    node<T> *temp1 = head, *temp2 = head;
    if (head == NULL)
    {
        return head;
    }
    if (temp1->data == val)
    {
        head = temp1->pt;
        delete temp1;m
    }
    else
    {
        temp1 = temp1->pt;
        while (temp1 != NULL && temp1->data != val)
        {
            temp1 = temp1->pt;
            temp2 = temp2->pt;
        }
        if (temp1 != NULL)
        {
            temp2->pt = temp1->pt;
            delete temp1;
        }
    }
    return head;
}
template <typename T = int>
node<T> *reverse(node<T> *head)
{
    node<T> *p1 = NULL, *p2 = head, *p3 = head->pt;
    while (p2 != NULL)
    {
        p2->pt = p1;
        p1 = p2;
        p2 = p3;
        if (p3 != NULL)
        {
            p3 = p3->pt;
        }
    }
    return p1;
}
template <typename T = int>
node<T> *sortconc(node<T> *l1, node<T> *l2)
{
    node<T> *p = l1, *q = l2, *r = NULL, *temp;
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data < l2->data)
    {
        r = l1;
        p = p->pt;
    }
    else
    {
        r = l2;
        q = q->pt;
    }
    temp = r;
    temp->pt = NULL;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            //printf("%d %d*\n", p->data, q->data);
            temp->pt = p;
            temp = p;
            p = p->pt;
        }
        else
        {
            //printf("%d %d*\n", p->data, q->data);
            temp->pt = q;
            temp = q;
            q = q->pt;
        }
    }
    if (p != NULL)
    {
        temp->pt = p;
    }
    else
    {
        temp->pt = q;
    }
    return r;
}
template <typename T = int>
void print(node<T> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->pt;
    }
    printf("\n");
}
int main()
{
    node<int> *l1 = NULL, *l2 = NULL, *l3;
    l1 = insert(l1, 5);
    l1 = insert(l1, 3);
    l1 = insert(l1, 1);
    l2 = insert(l2, 6);
    l2 = insert(l2, 4);
    l2 = insert(l2, 2);
    // printf("%d %d",l1->data,l2->data);
    l3 = sortconc(l1, l2);
    print(l3);
    return 0;
}
/*
    1->2->3->4->5
 p1 p2 p3
1)  p2->pt=p1;
2)  p1=p2;
3)  p2=p3;
4)  p3=p3->pt;
    1  2->3->4->5
    p1 p2 p3
    1<-2  3->4->5
       p1 p2 p3
    1<-2<-3  4->5
          p1 p2 p3
    1<-2<-3<-4  5
             p1 p2 p3
    1<-2<-3<-4<-5
                p1 p2 p3
             while(p2!=NULL)
             return p1;
5->4->3->2->1
1<-2<-3<-4<-5
*/