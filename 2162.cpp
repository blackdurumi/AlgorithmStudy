#include <iostream>
#include <algorithm>
#define N 3005

using namespace std;

typedef pair<int, int> pii;

int n, par[N], c[N];
pii arr[N][2];

int findpar(int index)
{
    if (index == par[index])
        return index;
    return par[index] = findpar(par[index]);
}

int ccw(pii p1, pii p2, pii p3)
{
    long long val = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

bool ismid(pii p1, pii p2, pii p3)
{
    if (p1.first > p3.first)
        swap(p1.first, p3.first);
    if (p1.second > p3.second)
        swap(p1.second, p3.second);

    if (p1.first <= p2.first && p2.first <= p3.first && p1.second <= p2.second && p2.second <= p3.second)
        return true;

    return false;
}

bool isCross(int l, int r)
{
    int ab, cd;
    ab = ccw(arr[l][0], arr[l][1], arr[r][0]) * ccw(arr[l][0], arr[l][1], arr[r][1]);
    if (ab > 0)
        return false;
    cd = ccw(arr[r][0], arr[r][1], arr[l][0]) * ccw(arr[r][0], arr[r][1], arr[l][1]);
    if (cd > 0)
        return false;

    if (ab == 0 && cd == 0)
    {
        return ismid(arr[l][0], arr[r][0], arr[l][1]) || ismid(arr[l][0], arr[r][1], arr[l][1]);
    }
    return true;
}

void join(int a, int b)
{
    a = findpar(a);
    b = findpar(b);
    if (a < b)
        par[b] = a;
    else
        par[a] = b;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i][0].first >> arr[i][0].second >> arr[i][1].first >> arr[i][1].second;
        par[i] = i;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (findpar(i) == findpar(j))
                continue;
            if (isCross(i, j))
                join(i, j);
        }
    }

    for (i = 1; i <= n; i++)
        c[findpar(i)]++;

    int mv = -1, cc = 0;
    for (i = 1; i <= n; i++)
    {
        mv = max(mv, c[i]);
        if (c[i])
            cc++;
    }

    cout << cc << endl;
    cout << mv << endl;

    return 0;
}