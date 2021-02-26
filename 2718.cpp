#include <iostream>
#include <algorithm>
#include <cstring>
#define N 1000000

using namespace std;

int n, d[N][5];

int dp(int index, int state)
{
    if (index == 0 && state == 0)
        return 1;
    if (index == 0 && state)
        return 0;
    if (index < 0)
        return 0;

    if (d[index][state] != -1)
        return d[index][state];
    int val;

    switch (state)
    {
    case 0:
        val = dp(index - 1, 0) + dp(index - 1, 1) + dp(index - 1, 2) + dp(index - 1, 3) + dp(index - 2, 0);
        break;
    case 1:
        val = dp(index - 1, 0) + dp(index - 1, 2);
        break;
    case 2:
        val = dp(index - 1, 0) + dp(index - 1, 1);
        break;
    case 3:
        val = dp(index - 1, 0) + dp(index - 1, 4);
        break;
    case 4:
        val = dp(index - 1, 3);
        break;
    }

    return d[index][state] = val;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, tc, i;
    cin >> tc;
    memset(d, -1, sizeof(d));
    for (t = 0; t < tc; t++)
    {
        cin >> n;
        cout << dp(n, 0) << endl;
    }

    return 0;
}