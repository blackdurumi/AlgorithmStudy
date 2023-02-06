#include<iostream>
#include<vector>
#include<cstring>
#define N 100005

using namespace std;

int n, map[N], check[N], inteam[N], visit[N], p, ans;

bool dfs(int index)
{
    if(check[index]){
        p=index;
        return true;
    }
    if(visit[index]) return false;
    visit[index]=1;
    check[index]=1;

    bool ret = dfs(map[index]);
    check[index]=0;
    if(!ret){
        inteam[index]=0;
        return false;
    }
    inteam[index]=1;
    ans++;
    if(index==p) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t, tc, i;
    cin >> tc;
    for(t=0; t<tc; t++){
        cin >> n;
        for(i=1; i<=n; i++) cin >> map[i];

        memset(visit, 0, sizeof(visit));
        for(i=1; i<=n; i++) inteam[i]=0;
        ans=0;
        for(i=1; i<=n; i++){
            if(inteam[i] || visit[i]) continue;
            dfs(i);
        }

        printf("%d\n", n-ans);
    }

    return 0;
}