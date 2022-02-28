#include<iostream>
#include<cstring>
#include<algorithm>
#define N 15

using namespace std;

int land[N][N], map[N][N], n, m;
int xx[4]={0, 0, 1, -1};
int yy[4]={1, -1, 0, 0};
int dist[N][N];

void land_check(int x, int y, int c){
    int i;
    map[x][y]=c;
    for(i=0; i<4; i++){
        int nx = x+xx[i];
        int ny = y+yy[i];
        if(land[nx][ny] && !map[nx][ny]) land_check(nx, ny, c);
    }
}

void check_dist(int x, int y){
    int i, j;
    for(i=0; i<4; i++){
        int nx = x+xx[i];
        int ny = y+yy[i];
        if(!map[nx][ny]){
            for(j=2; ; j++){
                int nx=x+xx[i]*j;
                int ny=y+yy[i]*j;
                if(nx<1 || nx>n || ny<1 || ny>m) break;
                int k = map[nx][ny];
                if(k){
                    if(j>2) dist[map[x][y]][k] = (dist[map[x][y]][k]==-1) ? j-1 : min(j-1, dist[map[x][y]][k]);
                    break;
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n >> m;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)
            cin >> land[i][j];
    }

    int c=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(land[i][j] && !map[i][j])
                land_check(i, j, ++c);
        }
    }

    memset(dist, -1, sizeof(dist));
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++){
            if(map[i][j]) check_dist(i, j);
        }
    }

    int connect[N], ans=0;
    for(i=1; i<=c; i++)
        connect[i]=i;
    for(int k=1; k<c; k++){
        int minv = 9999;
        for(i=1; i<=c; i++){
            for(j=i+1; j<=c; j++){
                if(dist[i][j]!=-1)
                    minv = min(minv, dist[i][j]);
            }
        }

        if(minv==9999){
            cout << "-1";
            return 0;
        }

        bool nxt=false;
        for(i=1; i<=c; i++){
            for(j=i+1; j<=c; j++){
                if(dist[i][j]==minv){
                    dist[i][j]=-1;
                    dist[j][i]=-1;
                    if(connect[i]==connect[j]) continue;

                    ans+=minv;
                    for(int l=1; l<=c; l++){
                        if(connect[l]==connect[j])
                            connect[l]=connect[i];
                    }
                    nxt=true;
                    break;
                }
            }
            if(nxt) break;
        }
        if(!nxt) k--;
    }
    cout << ans;

    return 0;
}