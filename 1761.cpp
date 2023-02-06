#include<iostream>
#include<vector>
#include<algorithm>
#define N 40005

using namespace std;

typedef pair<int, int> pii;

int n, parent[N][30], level[N], root[N];
vector<pii> dist[N];

void make_tree(int index, int lev, int par, int d)
{
    root[index]=d;
    level[index]=lev;
    parent[index][0]=par;
    int k=0;

    while(parent[parent[index][k]][k]>0) parent[index][k+1] = parent[parent[index][k]][k], k++;
    
    for(auto iter : dist[index]){
        if(level[iter.first]) continue;
        make_tree(iter.first, lev+1, index, d+iter.second);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, m, a, b, c;
    cin >> n;
    for(i=1; i<n; i++){
        cin >> a >> b >> c;
        dist[a].push_back({b, c});
        dist[b].push_back({a, c});
    }

    make_tree(1, 1, 0, 0);

    cin >> m;
    for(i=1; i<=m; i++){
        cin >> a >> b;
        int l = a, r = b;
        if(level[a]<level[b]) swap(a, b);

        for(j=20; j>=0; j--){
            if(level[a]==level[b]) break;
            if(level[parent[a][j]] >= level[b])
                a = parent[a][j];
        }

        for(j=20; j>=0; j--){
            if(a==b) break;
            if(parent[a][j]!=parent[b][j]){
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        while(a!=b) a = parent[a][0], b = parent[b][0];
        
        cout << root[l] + root[r] - 2*root[a] << endl;
    }

    return 0;
}