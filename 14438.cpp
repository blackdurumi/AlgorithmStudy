#include <iostream>
#include <algorithm>
#include<climits>
#define N 100005

using namespace std;

int n, m, arr[N], t[N * 3], x, y;

int make_tree(int start, int end, int index)
{
    if (start == end)
        return t[index] = arr[start];

    int mid = (start + end) / 2;
    return t[index] = min(make_tree(start, mid, index * 2), make_tree(mid + 1, end, index * 2 + 1));
}

int modify_tree(int start, int end, int index)
{
    if (start == x && end == x)
        return t[index] = y;

    int mid = (start + end) / 2;
    if (x <= mid)
        return t[index] = min(modify_tree(start, mid, index * 2), t[index * 2 + 1]);
    return t[index] = min(t[index * 2], modify_tree(mid + 1, end, index * 2 + 1));
}

int find(int start, int end, int index)
{
    if (x > end || y < start)
        return INT_MAX;

    int mid = (start + end) / 2;
    if (x <= start && end <= y)
        return t[index];
    return min(find(start, mid, index * 2), find(mid + 1, end, index * 2 + 1));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    make_tree(1, n, 1);

    cin >> m;
    for (i = 1; i <= m; i++)
    {
        int c;
        cin >> c >> x >> y;
        if (c == 1)
            modify_tree(1, n, 1);
        else if (c == 2)
            printf("%d\n", find(1, n, 1));
    }
    return 0;
}