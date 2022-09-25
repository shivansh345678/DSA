#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = n - 1; i >= 1; i--)
    {
        int l = 0;
        for (int j = 1; j <= i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int p = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = p;
                l = 1;
            }
        }
        if (l == 0)
        {
            break;
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 3];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}