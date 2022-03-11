#include<iostream>
#include<algorithm>
#include<vector>
#define N 10005

using namespace std;

int l[N], r[N], num, max_lev, ll[N], rr[N], check[N];

void dfs(int index, int level)
{
    max_lev=max(max_lev, level);

    if(l[index]) dfs(l[index], level+1);
    if(ll[level]==0) ll[level]=++num;
    else rr[level]=++num;
    if(r[index]) dfs(r[index], level+1);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i, root;
    cin >> n;
    for(i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(b!=-1) l[a]=b, check[b]=1;
        if(c!=-1) r[a]=c, check[c]=1;
    }

    for(i=1; i<=n; i++){
        if(!check[i]){
            root=i;
            break;
        }
    }

    dfs(root, 1);

    int ans=0, ansi;
    for(i=1; i<=max_lev; i++){
        if(!rr[i]) rr[i]=ll[i];
        if(ans<rr[i]-ll[i]+1){
            ans=rr[i]-ll[i]+1;
            ansi=i;
        }
    }
    cout << ansi << " " << ans;

    return 0;
}