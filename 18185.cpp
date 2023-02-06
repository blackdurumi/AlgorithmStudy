#include<iostream>
#include<algorithm>
#define N 10005

using namespace std;

int n, arr[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, ans=0;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];

    for(i=1; i<=n; i++){
        if(arr[i]==0) continue;

        if(arr[i+1]>arr[i+2]){
            int x = min(arr[i+1]-arr[i+2], arr[i]);
            ans += x*5;
            arr[i]-=x;
            arr[i+1]-=x;

            x = min(arr[i], min(arr[i+1], arr[i+2]));
            ans += x*7;
            arr[i]-=x;
            arr[i+1]-=x;
            arr[i+2]-=x;
        }
        else{
            int x = min(arr[i], min(arr[i+1], arr[i+2]));
            ans += x*7;
            arr[i]-=x;
            arr[i+1]-=x;
            arr[i+2]-=x;

            x = min(arr[i], arr[i+1]);
            ans += x*5;
            arr[i]-=x;
            arr[i+1]-=x;
        }

        ans += arr[i]*3;
    }
    cout << ans;
    
    return 0;
}