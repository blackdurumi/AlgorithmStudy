#include <iostream>
#include <algorithm>
#define N 15

using namespace std;

int check[N][N], arr[N][N], n, ans[2], crs[N * 5], rcrs[N * 5], color[N][N];

void dfs(int x, int y, int bs)
{
    check[x][y] = 1;
    crs[x + y] = 1;
    rcrs[x - y + N] = 1;

    ans[(x+y)%2] = max(ans[(x+y)%2], bs);

    int i, j;
    for (i = x; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (!check[i][j] && arr[i][j] && !crs[i + j] && !rcrs[i - j + N] && (x+y)%2==(i+j)%2)
                dfs(i, j, bs + 1);
        }
    }

    check[x][y] = 0;
    crs[x + y] = 0;
    rcrs[x - y + N] = 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            if ((i + j) % 2 == 0)
                color[i][j] = 1;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (arr[i][j])
                dfs(i, j, 1);
        }
    }

    cout << ans[0]+ans[1];

    return 0;
}