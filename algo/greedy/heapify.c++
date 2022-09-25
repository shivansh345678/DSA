#include <iostream>
using namespace std;
void fun(int arr[], int i, int n)
{
    int s = i;
    while (2 * s <= n)
    {
        if (2 * s + 1 <= n)
        {
            if (arr[2 * s] > arr[2 * s + 1])
            {
                if (arr[2 * s] > arr[s])
                {
                    int x = arr[s];
                    arr[s] = arr[2 * s];
                    arr[2 * s] = x;
                }
            }
            else
            {
                if (arr[2 * s + 1] > arr[s])
                {
                    int x = arr[s];
                    arr[s] = arr[2 * s + 1];
                    arr[2 * s + 1] = x;
                }
            }
        }
        else
        {
            if (arr[2 * s] > arr[s])
            {
                int x = arr[s];
                arr[s] = arr[2 * s];
                arr[2 * s] = x;
            }
        }
        s = s * 2;
    }
}
int main()
{
    cout <<"Enter the size of elements of array" << endl;
    int n;
    scanf("%d", &n);
    int arr[n + 4];
    cout << "Enter the elements" << endl;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        fun(arr, i, n);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}