#include<iostream>
#include<vector>
#include<queue>
#define N 105

using namespace std;

int n, m, check[N], ans[N], used[N];
vector<pair<int, int>> d[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;
    cin >> n >> m;
    for(i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        d[a].push_back({b, c});
        check[a]=1;
        used[b]++;
    }

    queue<int> q;
    q.push(n);
    ans[n]=1;

    while(!q.empty()){
        int head = q.front();
        q.pop();

        for(i=0; i<d[head].size(); i++){
            int p=d[head][i].first;
            int x=d[head][i].second;
            ans[p]+=ans[head]*x;

            if(--used[p]==0) q.push(p);
        }
    }

    for(i=1; i<=n; i++){
        if(!check[i]) cout << i << " " << ans[i] << endl;
    }

    return 0;
}