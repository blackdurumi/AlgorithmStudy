#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define N 1005

using namespace std;

typedef pair<int, int> pii;

int n, m, x;
vector<pii> map[N], remap[N];
int cost[N], tox[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, a, b, c;
    queue<int> q;

    cin >> n >> m >> x;
    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        remap[b].push_back(make_pair(a, c));
    }

    memset(cost, -1, sizeof(cost));

    cost[x] = 0;
    q.push(x);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(j=0; j<map[f].size(); j++){
            int idx = map[f][j].first;
            int w = map[f][j].second;
            if(cost[idx]>cost[f]+w || cost[idx]==-1){
                cost[idx] = cost[f]+w;
                q.push(idx);
            }
        }
    }

    for(i=1; i<=n; i++)
        tox[i] = cost[i];

    memset(cost, -1, sizeof(cost));
    cost[x]=0;
    q.push(x);

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(i=0; i<remap[f].size(); i++){
            int idx = remap[f][i].first;
            int w = remap[f][i].second;
            if(cost[idx]>cost[f]+w || cost[idx]==-1){
                cost[idx] = cost[f]+w;
                q.push(idx);
            }
        }
    }

    int ans=0;
    for(i=1; i<=n; i++){
        ans = max(ans, cost[i]+tox[i]);
    }

    cout << ans;

    return 0;
}