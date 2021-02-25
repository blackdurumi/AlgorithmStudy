#include <iostream>
#include <vector>
#define N 15
#define M 1000003

using namespace std;
typedef long long ll;

int n, s, e, t;
ll arr[N * 5][N * 5];
ll ans[N * 5][N * 5];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, k;
    scanf("%d %d %d %d", &n, &s, &e, &t);
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < 4; j++)
            arr[i * 5 - j - 1][i * 5 - j] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        getchar();
        for (j = 1; j <= n; j++)
        {
            int w = getchar() - '0';
            if (w)
                arr[i * 5][j * 5 - w + 1] = 1;
        }
    }

    for (i = 1; i <= n * 5; i++)
        ans[i][i] = 1;

    ll imsi[N * 5][N * 5];
    while (t)
    {
        if (t % 2)
        {
            for (i = 1; i <= n * 5; i++)
            {
                for (j = 1; j <= n * 5; j++)
                {
                    imsi[i][j] = 0;
                    for (k = 1; k <= n * 5; k++)
                    {
                        imsi[i][j] += ans[i][k] * arr[k][j];
                        imsi[i][j] %= M;
                    }
                }
            }
            for (i = 1; i <= n * 5; i++)
            {
                for (j = 1; j <= n * 5; j++)
                    ans[i][j] = imsi[i][j];
            }
        }
        for (i = 1; i <= n * 5; i++)
        {
            for (j = 1; j <= n * 5; j++)
            {
                imsi[i][j] = 0;
                for (k = 1; k <= n * 5; k++)
                {
                    imsi[i][j] += arr[i][k] * arr[k][j];
                    imsi[i][j] %= M;
                }
            }
        }
        for (i = 1; i <= n * 5; i++)
        {
            for (j = 1; j <= n * 5; j++)
                arr[i][j] = imsi[i][j];
        }
        t /= 2;
    }

    printf("%lld", ans[s * 5][e * 5]);

    return 0;
}