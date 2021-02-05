#include <iostream>
#include <algorithm>
#define N 50

using namespace std;

int n, l;
long long num, d[N][N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;
    cin >> n >> l >> num;

    d[0][0] = 1;
    d[1][0] = 1;
    d[1][1] = 1;

    for (i = 2; i < n; i++)
    {
        for (j = 0; j <= l && j <= i; j++)
        {
            if (j == 0 || j == i)
                d[i][j] = 1;
            else
                d[i][j] = d[i - 1][j] + d[i - 1][j - 1];
        }
    }

    int x = n;
    num--;
    while (x)
    {
        int prev = 0;
        for (i = 0; i <= l && i < x; i++)
            prev += d[x - 1][i];

        if (prev <= num)
        {
            num -= prev;
            x--;
            l--;
            cout << "1";
        }
        else
        {
            x--;
            cout << "0";
        }
    }

    return 0;
}