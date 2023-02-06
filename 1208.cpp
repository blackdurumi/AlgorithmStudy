#include<iostream>
#include<vector>
#include<map>
#define N 55

using namespace std;

typedef map<int, int> intmap;

int n, s;
long long ans=0;
vector<int> arr;
intmap ls;

void l(int index, int sum)
{
    if(index==n/2){
        ls[sum]++;
        return;
    }
    l(index+1, sum);
    l(index+1, sum+arr[index]);
}

void r(int index, int sum)
{
    if(index==n){
        ans += ls[s-sum];
        return;
    }
    r(index+1, sum);
    r(index+1, sum+arr[index]);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n >> s;
    for(i=0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }

    l(0, 0);
    r(n/2, 0);

    if(s==0) ans--;
    cout << ans;

    return 0;
}