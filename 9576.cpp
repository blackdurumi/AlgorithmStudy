#include <iostream>
#include <algorithm>
#include<cstring>
#define N 1005

using namespace std;

typedef pair<int, int> pii;

pii arr[N];
int n, m;
bool book[N];

bool comp(const pii &p1, const pii &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, t, tc, j;
    cin >> tc;
    for (t = 0; t < tc; t++)
    {
        int ans=0;
        cin >> n >> m;
        for (i = 0; i < m; i++)
            cin >> arr[i].first >> arr[i].second;

        sort(arr, arr + m, comp);
        memset(book, false, sizeof(book));

        for(i=0; i<m; i++){
            for(j=arr[i].first; j<=arr[i].second; j++){
                if(!book[j]){
                    book[j]=true;
                    ans++;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}