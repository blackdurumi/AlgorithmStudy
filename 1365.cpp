#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005

using namespace std;

int n, a;
vector<int> v;

void insert()
{
    int l=0, r=v.size()-1;
    
    while(l<r){
        int mid=(l+r)/2;
        
        if(v[mid]<a) l=mid+1;
        else r=mid;
    }

    if(v[l]<a) v.push_back(a);
    else v[l]=a;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;
    cin >> n;
    cin >> a;
    v.push_back(a);
    for(i=2; i<=n; i++){
        cin >> a;
        insert();
    }

    cout << n-v.size();

    return 0;
}