#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define N 55

using namespace std;

int map[N][N], l, r, n;
int group[N][N], g, gsum[N*N], gn[N*N];
int xx[4]={0, 0, 1, -1};
int yy[4]={1, -1, 0, 0};

void dfs(int x, int y)
{
    int i;
    group[x][y]=g;
    gsum[g]+=map[x][y];
    gn[g]++;

    for(i=0; i<4; i++){
        int nx=x+xx[i];
        int ny=y+yy[i];
        if(nx<1 || nx>n || ny<1 || ny>n || group[nx][ny]) continue;
        if(abs(map[x][y]-map[nx][ny])>=l && abs(map[x][y]-map[nx][ny])<=r) dfs(nx, ny);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n >> l >> r;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            cin >> map[i][j];
    }

    int turn=0;

    while(1){
        memset(group, 0, sizeof(group));
        memset(gsum, 0, sizeof(gsum));
        memset(gn, 0, sizeof(gn));
        g=1;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(!group[i][j]){
                    dfs(i, j);
                    g++;
                }
            }
        }
        if(g==n*n+1) break;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                map[i][j] = gsum[group[i][j]]/gn[group[i][j]];
                // cout << map[i][j] << " ";
            }
            // cout << endl;
        }
        turn++;
    }

    cout << turn << endl;
    
    return 0;
}