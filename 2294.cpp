#include<iostream>
#include<cstring>
#define N 10005

using namespace std;

int n, k, d[N], coin[105];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n >> k;
    for(i=1; i<=n; i++)
        cin >> coin[i];

    memset(d, -1, sizeof(d));
    d[0]=0;

    for(i=1; i<=k; i++){
        for(j=1; j<=n; j++){
            if(coin[j]>i) continue;
            if(d[i-coin[j]]==-1) continue;

            if(d[i]<0 || d[i]>d[i-coin[j]]+1)
                d[i]=d[i-coin[j]]+1;
        }
    }

    cout << d[k];

    return 0;
}