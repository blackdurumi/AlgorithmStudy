#include <iostream>
#include <algorithm>
#define N 1000005

using namespace std;
typedef long long ll;

int n, m, a, b;
ll arr[N * 9];

ll modify(int left, int right, int index)
{
    if (left == right)
        return arr[index] += b;

    int mid = (left + right) / 2;
    if (a <= mid)
        return arr[index] = modify(left, mid, index * 2) + arr[index * 2 + 1];
    return arr[index] = arr[index * 2] + modify(mid + 1, right, index * 2 + 1);
}

ll get(int left, int right, int index)
{
    if (b < left || a > right)
        return 0;
    if (a <= left && right <= b)
        return arr[index];

    int mid = (left + right) / 2;
    return get(left, mid, index * 2) + get(mid + 1, right, index * 2 + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int c;
        cin >> c >> a >> b;
        if (c == 1)
            modify(1, n, 1);
        else
            cout << get(1, n, 1) << endl;
    }

    return 0;
}