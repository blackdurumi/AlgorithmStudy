#include <iostream>
#define N 1000001

using namespace std;

int n, a, b, c;
int t[N * 4];

void update(int left, int right, int index, int target, int diff)
{
    if (left > target || right < target)
        return;
    t[index] += diff;
    if (left == right)
        return;

    int mid = (left + right) / 2;
    update(left, mid, index * 2, target, diff);
    update(mid + 1, right, index * 2 + 1, target, diff);
}

int query(int left, int right, int index, int target)
{
    if (left == right)
        return left;

    int mid = (left + right) / 2;
    if (t[index * 2] < target)
        return query(mid + 1, right, index * 2 + 1, target - t[index * 2]);
    return query(left, mid, index * 2, target);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            int tidx = query(1, N, 1, b);
            printf("%d\n", tidx);
            update(1, N, 1, tidx, -1);
        }
        else
        {
            cin >> b >> c;
            update(1, N, 1, b, c);
        }
    }

    return 0;
}