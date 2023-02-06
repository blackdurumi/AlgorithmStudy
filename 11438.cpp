#include<iostream>
#include<algorithm>
#include<vector>
#define N 100005

using namespace std;

int n, m, parent[N][30], depth[N];
vector<int> tree[N];

void dfs(int index)
{
    int i=0;
    while(parent[parent[index][i]][i]){
        parent[index][i+1] = parent[parent[index][i]][i];
        i++;
    }
    for(int next: tree[index]){
        if(!depth[next]){
            parent[next][0]=index;
            depth[next]=depth[index]+1;
            dfs(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, a, b;
    cin >> n;
    parent[1][0]=0;
    depth[1]=1;
    for(i=1; i<n; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);

    cin >> m;
    for(i=0; i<m; i++){
        cin >> a >> b;

        if(depth[a]<depth[b]) swap(a, b);
        
        for(j=20; j>=0; j--){
            if(depth[a]==depth[b]) break;
            if(depth[parent[a][j]]>=depth[b]) a = parent[a][j];
        }

        for(j=20; j>=0; j--){
            if(a==b) break;
            if(parent[a][j]!=parent[b][j]) a=parent[a][j], b=parent[b][j];
        }
        if(a!=b) a=parent[a][0];

        printf("%d\n", a);
    }

    return 0;
}