// AUTHOR - SHIVANSH
#include <iostream>
#include <cstring>
using namespace std;
int convrt(char st[])
{
    int p = strlen(st);
    int sum = st[0] - '0';
    for (int i = 1; i <= p - 1; i++)
    {
        sum = sum * 10 + st[i] - '0';
    }
    return sum;
}
int chck(char st[])
{
    int p = strlen(st);
    if (p == 1)
    {
        if (st[0] == '+' || st[0] == '-' || st[0] == '/' || st[0] == '*' || st[0] == '%')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (p == 2)
        {
            if (st[0] == '*' && st[1] == '*')
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }
}
int ras(int a, int b)
{
    int ans = 1;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a;
    }
    return ans;
}
int main()
{
    cout << "ENTER THE LENGTH OF YOUR EXPRESSION" << endl;
    int n, top;
    scanf("%d", &n);
    top = 0;
    int arr[n + 3];
    char st[n + 3][50];
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &st[i][1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (chck(&st[i][1]) == 1)
        {
            if (top <= 1)
            {
                printf("WRONG EXPRESSION");
                return 0;
            }
            int a = arr[top], b;
            top--;
            b = arr[top];
            top--;

            // printf("%d %d\n", a, b);
            if (st[i][1] == '+')
            {
                top++;
                arr[top] = a + b;
            }
            else if (st[i][1] == '-')
            {
                top++;
                arr[top] = b - a;
            }
            else if (st[i][1] == '*' && st[i][2] != '*')
            {
                top++;
                arr[top] = a * b;
            }
            else if (st[i][1] == '/')
            {
                top++;
                arr[top] = b / a;
            }
            else if (st[i][1] == '%')
            {
                top++;
                arr[top] = b % a;
            }
            else if (st[i][1] == '*' && st[i][2] == '*')
            {
                top++;
                arr[top] = ras(b, a);
            }
        }
        else
        {
            top++;
            arr[top] = convrt(&st[i][1]);
            // printf("%d\n", arr[top]);
        }
    }
    printf("%d\n", arr[1]);
    return 0;
}
//231*+9-