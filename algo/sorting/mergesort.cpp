//AUTHOR - SHIVANSH 
#include <iostream>
using namespace std;
void merge(int l, int mid, int r, int arr[])
{
    int ar1[mid - l + 2], ar2[r - mid + 1], p = 1, q = 1, u = 0;
    for (int i = l; i <= mid; i++)
    {
        u++;
        ar1[u] = arr[i];
    }
    u = 0;
    for (int i = mid + 1; i <= r; i++)
    {
        u++;
        ar2[u] = arr[i];
    }
    u = l - 1;
    while (p <= mid - l + 1 && q <= r - mid)
    {
        if (ar1[p] < ar2[q])
        {
            u++;
            arr[u] = ar1[p];
            p++;
        }
        else
        {
            u++;
            arr[u] = ar2[q];
            q++;
        }
    }
    while (p <= mid - l + 1)
    {
        u++;
        arr[u] = ar1[p];
        p++;
    }
    while (q <= r - mid)
    {
        u++;
        arr[u] = ar2[q];
        q++;
    }
}
void mergesort(int l, int r, int arr[])
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        mergesort(l, mid, arr);
        mergesort(mid + 1, r, arr);
        merge(l, mid, r, arr);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 4];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(1, n, arr);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}