#include <iostream>
using namespace std;
template <class T = int>
class queue
{
    int size = 0;
    int rear = 0;
    int front = 0;
    T *p;

public:
    queue(int a)
    {
        size = a + 1;
        p = new T[size];
        // if using malloc then
        // p=(T *)malloc(size*sizeof(T));
    }
    ~queue()
    {
        delete[] p;
        // if using free then
        // free(p);
    }
    void Insert(T a)
    {
        if ((rear + 1) % size == front)
        {
            cout << "Queue is full " << endl;
        }
        else
        {
            rear = (rear + 1) % size;
            p[rear] = a;
        }
    }
    T Delete(void)
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            front = (front + 1) % size;
            return p[front];
        }
    }
    int si_ze(void)
    {
        if (front <= rear)
        {
            return rear - front;
        }
        else
        {
            return (size - 1) - (front - rear - 1);
        }
    }
    void print(void)
    {
        int l = front;
        while (l != rear)
        {
            l = (l + 1) % size;
            printf("%d ", p[l]);
        }
    }
};
int main()
{
    int n, a;
    cout << "Enter the size and elements of queue" << endl;
    scanf("%d", &n);
    queue<int> q1(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        q1.Insert(a);
    }
    cout << "Poping all elements " << endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ",q1.Delete());
    }
    return 0;
}
