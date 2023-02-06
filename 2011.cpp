#include<iostream>
#include<string>
#include<algorithm>
#define N 5005
#define MOD 1000000

using namespace std;

int n, arr[N];
long long d[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i=0;
    string a;
    cin >> a;
    for(i=1; i<=a.size(); i++) arr[i]=a[i-1]-'0';
    n=a.size();

    if(arr[1]==0){
        cout << 0;
        return 0;
    }

    d[0]=1, d[1]=1;
    for(i=2; i<=n; i++){
        if(arr[i]==0){
            if(arr[i-1]==1 || arr[i-1]==2) d[i] = d[i-2];
            else break;
        }
        else{
            if(arr[i-1]==1) d[i] = max(d[i], d[i-1]+d[i-2]);
            if(arr[i-1]==2 &&arr[i]<=6) d[i] = max(d[i], d[i-1]+d[i-2]);
            d[i] = max(d[i], d[i-1]);
        }

        d[i]%=MOD;
    }

    cout << d[n];

    return 0;
}