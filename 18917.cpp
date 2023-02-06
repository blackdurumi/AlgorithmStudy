#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int m, i, c, a;
    long long sum=0, xsum=0;
    cin >> m;
    for(i=0; i<m; i++){
        cin >> c;
        if(c==1){
            cin >> a;
            sum+=a;
            xsum^=a;
        }
        if(c==2){
            cin >> a;
            sum-=a;
            xsum^=a;
        }
        if(c==3) printf("%lld\n", sum);
        if(c==4) printf("%lld\n", xsum);
    }

    return 0;
}