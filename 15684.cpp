#include<iostream>
#include<algorithm>

using namespace std;

int n, m, h, map[35][15], ans=-1;

bool check(){
    for(int i=1; i<n; i++){
        int f = 0, s = i;
        while(++f<=h){
            if(map[f][s]) s++;
            else if(map[f][s-1]) s--;
        }
        if(s!=i) return false;
    }

    return true;
}

void dfs(int x, int y, int c){
    int i, j;
    if(check()){
        ans = (ans==-1) ? c : min(ans, c);
        return;
    }
    if(c>=3) return;
    for(i=x; i<=h; i++){
        for(j=(i==x) ? y+1 : 1; j<n; j++){
            if(map[i][j] || map[i][j-1] || map[i][j+1]) continue;

            map[i][j]=1;
            dfs(i, j, c+1);
            map[i][j]=0;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n >> m >> h;
    for(i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    dfs(1, 0, 0);

    cout << ans;

    return 0;
}