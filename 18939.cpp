#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int n, m, k, t, tc;
    cin >> t;
    for(tc=0; tc<t; tc++){
        cin >> n >> m >> k;

        if(max(n,m)<k*2) printf("Yuto\n");
        else if((n*m)%2==0) printf("Platina\n");
        else printf("Yuto\n");
    }

    return 0;
}