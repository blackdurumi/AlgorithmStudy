#include <iostream>
#include <cstring>
#include <cmath>
#define N 105

using namespace std;

int n, l, arr[N][N], ans, built[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, k;
    cin >> n >> l;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cin >> arr[i][j];
    }

    for (i = 1; i <= n; i++)
    {
        memset(built, 0, sizeof(built));
        for (j = 2; j <= n; j++)
        {
            if (abs(arr[i][j - 1] - arr[i][j] > 1))
                break;
            if (arr[i][j - 1] > arr[i][j])
            {
                if (j + l - 1 > n)
                    break;
                for (k = j; k < j + l; k++)
                {
                    if (arr[i][j] != arr[i][k] || built[k])
                        break;
                }
                if (k < j + l)
                    break;
                for (k = j; k < j + l; k++)
                    built[k] = 1;
            }
            else if (arr[i][j - 1] < arr[i][j])
            {
                if (j <= l)
                    break;
                for (k = j - l; k < j; k++)
                {
                    if (arr[i][j - 1] != arr[i][k] || built[k])
                        break;
                }
                if (k < j)
                    break;
                for (k = j - l; k < j; k++)
                    built[k] = 1;
            }
        }
        if (j > n)
            ans++;
    }

    for (i = 1; i <= n; i++)
    {
        memset(built, 0, sizeof(built));
        for (j = 2; j <= n; j++)
        {
            if (abs(arr[j][i] - arr[j - 1][i] > 1))
                break;
            if (arr[j][i] < arr[j - 1][i])
            {
                if (j + l - 1 > n)
                    break;
                for (k = j; k < j + l; k++)
                {
                    if (arr[j][i] != arr[k][i] || built[k])
                        break;
                }
                if (k < j + l)
                    break;
                for (k = j; k < j + l; k++)
                    built[k] = 1;
            }
            else if (arr[j][i] > arr[j - 1][i])
            {
                if (j <= l)
                    break;
                for (k = j - l; k < j; k++)
                {
                    if (arr[j - 1][i] != arr[k][i] || built[k])
                        break;
                }
                if (k < j)
                    break;
                for (k = j - l; k < j; k++)
                    built[k] = 1;
            }
        }
        if (j > n)
            ans++;
    }

    cout << ans;

    return 0;
}