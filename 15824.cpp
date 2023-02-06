#include<iostream>
#include<vector>
#include<algorithm>
#define MOD 1000000007

using namespace std;

typedef long long ll;

vector<ll> arr;

ll power(ll a, ll exp)
{
    if(exp==0) return 1;
    return exp%2 ? (a*power(a, exp/2)*power(a, exp/2))%MOD : power(a, exp/2)*power(a, exp/2)%MOD;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i;
    cin >> n;
    for(i=1; i<=n; i++){
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());

    ll ans=0;
    for(i=0; i<n; i++){
        ans+=(arr[i]%MOD)*(power(2,i)-power(2,n-i-1))%MOD;
        ans%=MOD;
        if(ans<0) ans+=MOD;
    }

    cout << ans;

    return 0;
}