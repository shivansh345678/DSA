#include <iostream>
using namespace std;
int rbs(int arr[], int l, int r, int x)
{
    if (l > r)
    {
        return -1;
    }
    int mid = (r + l) / 2;
    if (arr[mid] == x)
    {
        return mid;
    }
    if (arr[mid] < x)
    {
        rbs(arr, mid + 1, r, x);
    }
    else
    {
        rbs(arr, l, mid - 1, x);
    }
}
int main()
{
    int n, p, x;
    scanf("%d %d", &n, &p);
    int arr[n + 3];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    x = rbs(arr, 1, n, p);
    if (x == -1)
    {
        int a;
        cout << "ENTER THE POSITION TO ENTER P" << '\n';
        cin >> a;
        arr[n + 1] = arr[n];
        for (int i = n; i > a; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[a] = p;
        cout << "ELEMENTS AFTER ADDING THE GIVEN ELEMENT" << endl;
        for (int i = 1; i <= n + 1; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = x; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
        cout << "ELEMENTS AFTER REMOVING THE GIVEN ELEMENT" << endl;
        for (int i = 1; i <= n - 1; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
