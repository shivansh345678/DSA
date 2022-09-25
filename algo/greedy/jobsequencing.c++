#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
bool comp(int *pa, int *pb)
{
    return *(pa + 1) > *(pb + 1);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int n, s = 0, ans = 0;
    scanf("%d", &n);
    set<int> st;
    int **arr = new int *[n + 3];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = new int[2];
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        s = max(arr[i][0], s);
    }
    for (int i = 1; i <= s; i++)
    {
        st.insert(i);
    }
    sort(arr + 1, arr + 1 + n, comp);
    for (int i = 1; i <= n; i++)
    {
        if (st.size())
        {
            auto it = st.upper_bound(ar[i][0]);
            if (it != st.begin())
            {
                it--;
                c++;
                st.erase(*it);
                ans = ans + ar[i][1];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
