#include<iostream>
#include<algorithm>
#include<cstring>
#define N 10005

using namespace std;

int n, m, arr[30], d[30][N];

int f(int x, int y)
{
    if(d[x][y]!=-1) return d[x][y];
    if(y==0) return 1;

    d[x][y]=0;
    for(int i=0; i*arr[x]<=y; i++)
        d[x][y] += f(x-1, y-arr[x]*i);

    return d[x][y];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t, tc;

    cin >> tc;
    for(t=0; t<tc; t++){
        cin >> n;
        int i, j;
        for(i=1; i<=n; i++)
            cin >> arr[i];
        cin >> m;

        memset(d, -1, sizeof(d));
        
        for(i=0; i<=m; i++)
            d[1][i] = (i%arr[1]==0) ? 1 : 0;
        cout << f(n, m) << endl;
    }

    return 0;
}