#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define N 100005
#define M 1005

using namespace std;

int n, k, m, d[N + M];
vector<vector<int>> arr;
queue<int> q;
bool check[N + M];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, temp;
    cin >> n >> k >> m;
    arr.resize(n + m + 1);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < k; j++)
        {
            cin >> temp;
            arr[i + n + 1].push_back(temp);
            arr[temp].push_back(i + n + 1);
        }
    }

    q.push(1);
    check[1] = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        if (head == n)
        {
            cout << d[head] / 2 + 1;
            return 0;
        }

        for (i = 0; i < arr[head].size(); i++)
        {
            if (check[arr[head][i]])
                continue;

            check[arr[head][i]]=true;
            d[arr[head][i]] = d[head] + 1;

            q.push(arr[head][i]);
        }
    }

    cout << "-1";

    return 0;
}