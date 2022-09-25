// Implentation of stack using array-:) first in last out
#include <iostream>
using namespace std;
template <class T = int>
class stack
{
    int top = -1;
    int size = 0;
    T *p = NULL;

public:
    stack(int a)
    {
        size = a;
        p = new T[size];
        // if using malloc then
        // p=(T *)malloc(size*sizeof(T));
    }
    ~stack(void)
    {
        // cout<<"destructor called"<<endl;
        delete[] p;
        // if using free then
        // free(p);
    }
    void push(T a)
    {
        if (top + 1 >= size)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            p[top] = a;
        }
    }
    T pop(void)
    {
        if (top <= -1)
        {
            cout << "Stack is empty" << endl;
            return top;
        }
        else
        {
            T c = p[top];
            top--;
            return c;
        }
    }
    int si_ze(void)
    {
        return top + 1;
    }
    int capacity(void)
    {
        return size;
    }
};
int main()
{
    int n, a;
    cout << "enter the number of element to enter in  stack" << endl;
    scanf("%d", &n);
    stack<int> s1(n + 2);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        s1.push(a);
    }
    cout << "poped elements from stack" << endl;
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", s1.pop());
    }
    return 0;
}
