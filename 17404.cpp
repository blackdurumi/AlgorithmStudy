#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define N 1005

using namespace std;

int arr[N][3], D[N][3], ans = INT_MAX, ban;

int d(int n, int f)
{
    if (n == 1 && ban == f)
        return 99999999;
    if (D[n][f] != -1)
        return D[n][f];

    return D[n][f] = arr[n][f] + min(d(n - 1, (f + 1) % 3), d(n - 1, (f + 2) % 3));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, k, n;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    for (i = 0; i < 3; i++)
    {
        memset(D, -1, sizeof(D));
        D[1][0] = arr[1][0];
        D[1][1] = arr[1][1];
        D[1][2] = arr[1][2];

        ban = i;
        ans = min(ans, d(n, i));
    }

    cout << ans;

    return 0;
}