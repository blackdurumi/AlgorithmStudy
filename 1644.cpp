#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#define N 4000005

using namespace std;

int n;
int pn[N], d[N];
vector<int> p;
queue<int> q;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n;
    pn[1] = 1;
    for(i=2; i<=sqrt(n); i++){
        j=i*2;
        while(j<=n){
            pn[j]=1;
            j+=i;
        }
    }
    
    for(i=1; i<=n; i++){
        if(!pn[i]) p.push_back(i);
    }

    int ans=0, sum=0;
    for(i=0; i<p.size(); i++){
        sum+=p[i];
        q.push(p[i]);

        if(sum==n) ans++;

        while(sum>n){
            sum-=q.front();
            q.pop();
            if(sum==n) ans++;
        }
    }

    cout << ans;

    return 0;
}