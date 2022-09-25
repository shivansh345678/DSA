#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the number of vertices and edges in graph" << endl;
    int n, m;
    scanf("%d %d", &n, &m);
    int adj1[n + 3][n + 3], adj2[n + 3][n + 3];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj1[i][j] = 0;
            adj2[i][j] = 0;
        }
    }
    cout << "Enter the edges of graph" << endl;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        adj1[a][b] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj1[i][j])
            {
                adj2[j][i] = 1;
            }
        }
    }
    cout << "The transpose graph edges are " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adj2[i][j])
            {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}