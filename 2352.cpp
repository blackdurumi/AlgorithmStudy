#include<iostream>
#include<vector>
#include<algorithm>
#define N 40005

using namespace std;

int a, n;
vector<int> ans;

void insert()
{
    int l=0;
    int r=ans.size();

    while(l<r){
        int mid=(l+r)/2;
        if(ans[mid]>=a) r=mid;
        else l=mid+1;
    }
    if(ans[l]>a) ans[l]=a;
    else if(l>=ans.size()) ans.push_back(a);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;
    cin >> n;
    cin >> a;
    ans.push_back(a);
    for(i=2; i<=n; i++){
        cin >> a;
        insert();
    }

    cout << ans.size();

    return 0;
}