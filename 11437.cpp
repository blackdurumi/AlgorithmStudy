#include<iostream>
#include<vector>
#include<algorithm>
#define N 50005

using namespace std;

vector<int> tree[N];
int parent[N][30], level[N];

void dfs(int index)
{
    int i=0;
    while(parent[parent[index][i]][i]){
        parent[index][i+1]=parent[parent[index][i]][i];
        i++;
    }

    for(auto iter : tree[index])
    {
        if(level[iter]) continue;
        parent[iter][0]=index;
        level[iter]=level[index]+1;
        dfs(iter);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i, j, a, b, m;
    cin >> n;
    for(i=1; i<n; i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    level[1]=1;
    dfs(1);

    cin >> m;
    for(i=1; i<=m; i++){
        cin >> a >> b;
        
        if(level[a]<level[b]) swap(a, b);

        for(j=20; j>=0; j--){
            if(level[a]==level[b]) break;
            if(level[parent[a][j]]>=level[b]) a=parent[a][j];
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