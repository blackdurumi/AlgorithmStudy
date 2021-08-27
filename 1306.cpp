#include <iostream>
#include <algorithm>
#define N 1000005

using namespace std;

int n, m, arr[N], st[N * 3];

int init(int left, int right, int index)
{
    if (left == right)
        return st[index] = arr[left];
    int mid = (left + right) / 2;

    return st[index] = max(init(left, mid, index * 2), init(mid + 1, right, index * 2 + 1));
}

int getval(int head, int tail, int left, int right, int index)
{
    if (right < head || tail < left)
        return 0;
    if (head <= left && right <= tail)
        return st[index];
    int mid = (left + right) / 2;

    return max(getval(head, tail, left, mid, index * 2), getval(head, tail, mid + 1, right, index * 2 + 1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;
    cin >> n >> m;

    for (i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, n, 1);

    for (i = m; i <= n - m + 1; i++)
        cout << getval(i - m + 1, i + m - 1, 1, n, 1) << " ";

    return 0;
}