#include <iostream>
#define N 100005
#define swap(x, y, z) z=x,x=y,y=z

using namespace std;
typedef long long ll;

ll n, q, arr[N];
ll t[N * 3];
ll x, y, a, b;

ll make_tree(ll start, ll end, ll index)
{
    if (start == end)
        return t[index] = arr[start];

    ll mid = (start + end) / 2;
    return t[index] = make_tree(start, mid, index * 2) + make_tree(mid + 1, end, index * 2 + 1);
}

ll get_sum(ll start, ll end, ll index)
{
    if (end < x || start > y)
        return 0;
    if (x <= start && end <= y)
        return t[index];
    ll mid = (start + end) / 2;
    return get_sum(start, mid, index * 2) + get_sum(mid + 1, end, index * 2 + 1);
}

ll modify_tree(ll start, ll end, ll index)
{
    ll mid = (start + end) / 2;

    if (start == end)
        return t[index] = b;

    if (a <= mid)
        return t[index] = modify_tree(start, mid, index * 2) + t[index * 2 + 1];
    else
        return t[index] = t[index * 2] + modify_tree(mid + 1, end, index * 2 + 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, temp;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    make_tree(1, n, 1);

    for (i = 1; i <= q; i++)
    {
        cin >> x >> y >> a >> b;
        if(x>y) swap(x, y, temp);

        printf("%lld\n", get_sum(1,n,1));
        modify_tree(1, n, 1);
    }

    return 0;
}