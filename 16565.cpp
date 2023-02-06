#include<iostream>
#define N 55
#define MOD 10007

using namespace std;

int c[N][N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, n;
    cin >> n;

    for(i=0; i<=52; i++){
        c[i][0]=1;
        c[i][i]=1;
        for(j=1; j<=i/2; j++){
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
            c[i][i-j] = c[i][j];
        }
    }

    int ans=0;
    for(i=1; i<=n/4; i++){
        if(i%2==1) ans += c[13][i]*c[52-i*4][n-i*4];
        else ans -= c[13][i]*c[52-i*4][n-i*4];

        ans %= MOD;
        if(ans<0) ans+=MOD;
    }
    if(ans<0) ans+=MOD;

    cout << ans;

    return 0;
}