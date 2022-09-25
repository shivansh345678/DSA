#include <iostream>
using namespace std;
void insert(int arr[], int u, int a)
{
    arr[u] = a;
    int s = u;
    while (s > 1)
    {
        int p = s / 2;
        if (arr[p] > a)
        {
            int l = arr[p];
            arr[p] = a;
            arr[s] = l;
        }
        else
        {
            break;
        }
        s = s / 2;
    }
}
int dlt(int arr[], int *u)
{

    int val = arr[1];
    arr[1] = arr[(*u)];
    arr[(*u)] = val;
    (*u)--;
    int s = (*u), p = 1;
    while (2 * p <= s)
    {
        if (2 * p + 1 <= s)
        {
            if (arr[2 * p] < arr[2 * p + 1])
            {
                if (arr[p] > arr[2 * p])
                {
                    int v = arr[p];
                    arr[p] = arr[2 * p];
                    arr[2 * p] = v;
                    p = 2 * p;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (arr[p] > arr[2 * p + 1])
                {
                    int v = arr[p];
                    arr[p] = arr[2 * p + 1];
                    arr[2 * p + 1] = v;
                    p = 2 * p + 1;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            if (arr[2 * p] < arr[p])
            {
                int v = arr[2 * p];
                arr[2 * p] = arr[p];
                arr[p] = v;
                p = 2 * p;
            }
            else
            {
                break;
            }
        }
    }
    return val;
}
void print(int arr[], int u)
{
    for (int i = 1; i <= u; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    cout << "Enter the number of elements in your heap" << endl;
    int n;
    scanf("%d", &n);
    int arr[n + 4], u = 0, a, ans[n + 4], p = 0;
    cout << "Enter the elements" << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        u++;
        insert(arr, u, a);
    }
    for (int i = 1; i <= n; i++)
    {
        p = dlt(arr, &u);
        ans[i] = p;
    }
    print(ans, n);
}