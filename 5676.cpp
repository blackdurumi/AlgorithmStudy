#include <iostream>
#include<cstring>
#define N 100005

using namespace std;

int n, k, arr[N], st[N * 99], a, b;

int eval(int value)
{
    if (value > 0)
        return 1;
    else if (value < 0)
        return -1;
    return 0;
}

int init(int left, int right, int index)
{
    if (left == right)
        return st[index] = eval(arr[left]);

    int mid = (left + right) / 2;
    return st[index] = init(left, mid, index * 2) * init(mid + 1, right, index * 2 + 1);
}

int modify(int left, int right, int index)
{
    if (left == right)
        return st[index] = eval(b);

    int mid = (left + right) / 2;
    if (a <= mid)
        return st[index] = modify(left, mid, index * 2) * st[index * 2 + 1];
    return st[index] = st[index * 2] * modify(mid + 1, right, index * 2 + 1);
}

int get(int left, int right, int index)
{
    if (a <= left && right <= b)
        return st[index];
    if (b < left || right < a)
        return 1;

    int mid = (left + right) / 2;
    return get(left, mid, index * 2) * get(mid + 1, right, index * 2 + 1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i;
    char c;

    while (cin >> n)
    {
        cin >> k;
        memset(st, 0, sizeof(st));
        for (i = 1; i <= n; i++)
            cin >> arr[i];
        init(1, n, 1);

        for (i = 0; i < k; i++)
        {
            cin >> c >> a >> b;

            if (c == 'C')
                modify(1, n, 1);
            else
            {
                int ans = get(1, n, 1);
                if (ans > 0)
                    printf("+");
                else if (ans < 0)
                    printf("-");
                else
                    printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}