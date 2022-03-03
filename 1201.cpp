#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, m, k, i;

    cin >> n >> m >> k;

    if(n>m*k || m+k-1>n){
        cout << "-1";
        return 0;
    }

    vector<int> arr;
    arr.push_back(k);
    m--;
    n-=k;

    while(n){
        arr.push_back(min(n/m+n%m, k));
        n-=min(n/m+n%m, k);
        m--;
    }

    int num=1;
    while(!arr.empty()){
        int p = arr.back();
        arr.pop_back();

        for(i=num; i<num+p; i++) cout << num+p-i+num-1 << " ";
        num+=p;
    }
 
    return 0;
}