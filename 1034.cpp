#include<iostream>
#include<vector>
#include<algorithm>
#define N 55

using namespace std;

int n, m, k;
string lamp[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, ans=0;
    cin >> n >> m;
    for(i=1; i<=n; i++) cin >> lamp[i];
    cin >> k;

    for(i=1; i<=n; i++){
        int zeros=0;
        for(j=0; j<m; j++){
            if(lamp[i][j]=='0') zeros++;
        }

        if(k>=zeros && (k-zeros)%2==0){
            int candi=1;
            for(j=i+1; j<=n; j++){
                if(lamp[i].compare(lamp[j])==0)
                    candi++;
            }
            ans = max(ans, candi);
        }
    }

    cout << ans;

    return 0;
}