#include<iostream>
#include<vector>
#define N 100005

using namespace std;

int n, arr[N], check[N];
vector<pair<int, int>> map[N], parent[N];

void dfs(int index)
{
    int i;

    check[index]=1;
    for(i=0; i<map[index].size(); i++){
        int idx=map[index][i].first;
        int cost=map[index][i].second;
        if(check[idx]) continue;
        parent[idx].push_back({index, cost});
        dfs(idx);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    for(i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }

    dfs(1);
    parent[1].push_back({1, 0});

    for(i=1; i<=16; i++){
        bool in=false;
        for(j=1; j<=n; j++){
            if(parent[j].size()<=i-1) continue;
            if(parent[parent[j][i-1].first].size()<=i-1) continue;
            in=true;
            parent[j].push_back({parent[parent[j][i-1].first][i-1].first, parent[j][i-1].second+parent[parent[j][i-1].first][i-1].second});
        }
        if(!in) break;
    }

    for(i=1; i<=n; i++){
        int cur=i;
        for(j=parent[cur].size()-1; j>=0; j--){
            if(arr[i]<parent[cur][j].second) continue;
            arr[i]-=parent[cur][j].second;
            cur=parent[cur][j].first;
        }
        printf("%d\n", cur);
    }

    return 0;
}