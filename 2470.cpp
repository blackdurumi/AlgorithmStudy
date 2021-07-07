#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#define N 100005

using namespace std;

int n, arr[N], ans[3];

void find_ans(int x, int left, int right, int ban)
{
    if (left + 1 >= right)
    {
        if (abs(x - arr[left]) > abs(x - arr[right]) && right != ban)
        {
            if (abs(x - arr[right]) < ans[0])
            {
                ans[0] = abs(x - arr[right]);
                ans[1] = -x;
                ans[2] = arr[right];
            }
        }
        else
        {
            if (abs(x - arr[left]) < ans[0] && left != ban)
            {
                ans[0] = abs(x - arr[left]);
                ans[1] = -x;
                ans[2] = arr[left];
            }
        }
        return;
    }
    int mid = (left + right) / 2;

    if (arr[mid] < x)
        find_ans(x, mid + 1, right, ban);
    else
        find_ans(x, left, mid, ban);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i;
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    ans[0] = INT_MAX;

    for (i = 1; i <= n; i++)
        find_ans(-arr[i], 1, n, i);

    if (ans[1] < ans[2])
        cout << ans[1] << " " << ans[2];
    else
        cout << ans[2] << " " << ans[1];

    return 0;
}