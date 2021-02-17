#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define N 105

using namespace std;

int n, arr[N][N], in, ax;
queue<pair<int, int>> q;
int xx[4] = {0, 0, -1, 1};
int yy[4] = {1, -1, 0, 0};
bool check[N][N];

bool cross(int minv, int maxv)
{
    if(arr[1][1]<minv || arr[1][1]>maxv) return false;
    int i;
    while (!q.empty())
        q.pop();
    memset(check, false, sizeof(check));

    q.push(make_pair(1, 1));
    check[1][1] = true;
    while (!q.empty())
    {
        if (q.front() == make_pair(n, n))
            return true;
            
        for (i = 0; i < 4; i++)
        {
            int nx = q.front().first + xx[i];
            int ny = q.front().second + yy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n)
                continue;

            if (!check[nx][ny] && arr[nx][ny] >= minv && arr[nx][ny] <= maxv){
                check[nx][ny]=true;
                q.push(make_pair(nx, ny));
            }
        }
        q.pop();
    }

    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;

    cin >> n;
    in = 99999;
    ax = -99999;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            in = min(in, arr[i][j]);
            ax = max(ax, arr[i][j]);
        }
    }

    int left = in;
    int right = in;
    int ans = 99999;
    while (left <= right && right <= ax)
    {
        if (cross(left, right))
        {
            ans = min(ans, right - left);
            left++;
        }
        else
            right++;
    }

    cout << ans;

    return 0;
}