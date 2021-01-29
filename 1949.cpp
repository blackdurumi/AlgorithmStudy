#include <iostream>
#include <algorithm>
#define N 10005

using namespace std;

int n, arr[N];
bool matrix[N][N];
int d[N][2], check[N];

int proc(int index, int sel)
{
    int i;

    if (d[index][sel])
        return d[index][sel];

    check[index] = 1;
    if (sel)
        d[index][sel] = arr[index];
    for (i = 1; i <= n; i++)
    {
        if (matrix[index][i] && !check[i])
        {
            if (sel)
                d[index][sel] += proc(i, 0);
            else
                d[index][sel] += max(proc(i, 0), proc(i, 1));
        }
    }

    check[index] = 0;
    return d[index][sel];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    for (i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    proc(1, 0);
    proc(1, 1);

    cout << max(d[1][0], d[1][1]);
}