#include <iostream>
#include <algorithm>
#include <vector>
#define N 10005

using namespace std;

int n, arr[N], d[N][2], check[N], val;
bool matrix[N][N];
vector<int> ans;

int eval(int index, int isSel)
{
    int i;

    if (d[index][isSel])
        return d[index][isSel];

    check[index] = 1;
    if (isSel)
        d[index][isSel] = arr[index];
    for (i = 1; i <= n; i++)
    {
        if (matrix[index][i] && !check[i])
        {
            if (isSel)
                d[index][isSel] += eval(i, 0);
            else
                d[index][isSel] += max(eval(i, 0), eval(i, 1));
        }
    }
    check[index] = 0;

    return d[index][isSel];
}

int find(int index, int isSel)
{
    int i;

    if (isSel)
        ans.push_back(index);

    check[index] = 1;
    for (i = 1; i <= n; i++)
    {
        if (matrix[index][i] && !check[i])
        {
            if (isSel)
                find(i, 0);
            else
            {
                if (d[i][0] < d[i][1])
                    find(i, i);
                else
                    find(i, 0);
            }
        }
    }
    check[index] = 0;

    return d[index][isSel];
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, a, b;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    for (i = 1; i < n; i++)
    {
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    val = max(eval(1, 0), eval(1, 1));
    int res = 0;
    if (d[1][0] < d[1][1])
        res = 1;
    cout << val << endl;

    find(1, res);
    sort(ans.begin(), ans.end());
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}