#include<iostream>
#include<cstring>
#include<algorithm>
#define N 105

using namespace std;

int n, map[N][N], check[N][N], sec[N][N], l, land[N][N];
int xx[4]={0, 0, 1, -1};
int yy[4]={1, -1, 0, 0};

void dfs(int x, int y)
{
    check[x][y]=1;
    map[x][y]=l;

    for(int i=0; i<4; i++){
        int nx=x+xx[i];
        int ny=y+yy[i];

        if(nx<1 || ny<1 || nx>n || ny>n) continue;
        if(check[nx][ny]) continue;
        if(!land[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i, j;
	cin >> n;
    memset(sec, -1, sizeof(sec));

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> land[i][j];
            if(land[i][j]==1) sec[i][j]=0;
        }
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(land[i][j] && !map[i][j]) ++l, dfs(i, j);
        }
    }

    int t=0;
    int ans=99999;
    while(1)
    {
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                if(sec[i][j]==t){
                    for(int k=0; k<4; k++){
                        int nx=i+xx[k];
                        int ny=j+yy[k];
                        if(nx<1 || ny<1 || nx>n || ny>n) continue;

                        if(sec[nx][ny]!=-1 && map[i][j]!=map[nx][ny]){
                            ans = min(ans, t+sec[nx][ny]);
                            continue;
                        }

                        if(sec[nx][ny]!=-1) continue;

                        sec[nx][ny]=t+1;
                        map[nx][ny]=map[i][j];
                    }
                }
            }
        }
        if(ans!=99999) break;
        t++;
    }

    cout << ans;

	return 0;
}