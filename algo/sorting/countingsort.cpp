#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 4], fr1[200004] = {0}, fr2[200004] = {0};
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0)
        {
            fr1[arr[i]]++;
        }
        else
        {
            fr2[-arr[i]]++;
        }
    }
    for (int i = -200000; i <= -1; i++)
    {
        if (fr2[-i])
        {
            int s = fr2[-i];
            while (s)
            {
                printf("%d ",i);
                s--;
            }
        }
    }
    for (int i = 0; i <= 200000; i++)
    {
        if (fr1[i])
        {
            int s = fr1[i];
            while (s)
            {
                printf("%d ", i);
                s--;
            }
        }
    }
    printf("\n");
    return 0;
}