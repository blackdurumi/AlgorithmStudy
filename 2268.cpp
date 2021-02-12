#include <iostream>
#include <algorithm>
#define N 1000005

using namespace std;
int n, m, a, b;
typedef long long ll;
ll arr[N * 9];

ll get(int left, int right, int index)
{
    if (a <= left && right <= b)
        return arr[index];
    if (b < left || right < a)
        return 0;

    int mid = (left + right) / 2;

    return get(left, mid, index * 2) + get(mid + 1, right, index * 2 + 1);
}

ll modify(int left, int right, int index)
{
    if (left == right)
        return arr[index] = b;

    int mid = (left + right) / 2;
    if (a <= mid)
        return arr[index] = modify(left, mid, index * 2) + arr[index * 2 + 1];
    return arr[index] = arr[index * 2] + modify(mid + 1, right, index * 2 + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, c, temp;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &c, &a, &b);
        if (c == 0){
            if(a>b) swap(a,b);
            printf("%lld\n", get(1, n, 1));
        }
        else
            modify(1, n, 1);
    }

    return 0;
}