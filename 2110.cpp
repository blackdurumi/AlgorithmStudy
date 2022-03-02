#include<iostream>
#include<vector>
#include<algorithm>
#define N 200005

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c, i, arr[N];
    cin >> n >> c;

    for(i=0; i<n; i++) cin >> arr[i];
    
    sort(arr, arr+n);

    int l=0, r=arr[n-1]-arr[0];
    while(l<r){
        int d=arr[0], cc=1;
        int key = (l+r+1)/2;

        for(i=1; i<n; i++){
            if(arr[i]-d>=key){
                d=arr[i];
                cc++;
            }
        }

        if(cc>c) l=key+1;
        else if(cc<c) r=key-1;
        else if(r==key) l=key+1;
        else l=key;
    }

    cout << r;

    return 0;
}