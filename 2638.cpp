#include<iostream>
#include<cstring>
#include<queue>
#define N 105

using namespace std;

typedef pair<int, int> pii;

int n, m, map[N][N], c, check[N][N];
int xx[4]={0, 0, 1, -1};
int yy[4]={1, -1, 0, 0};

void bfs(int x, int y)
{
    queue<pii> q;

    q.push({x, y});
    memset(check, 0, sizeof(check));
    while(!q.empty()){
        pii head = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nx=head.first+xx[i];
            int ny=head.second+yy[i];

            if(nx<1 || ny<1 || nx>n || ny>m) continue;
            if(check[nx][ny] || map[nx][ny]) continue;
            check[nx][ny]=1;
            map[nx][ny]=2;
            q.push({nx, ny});
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
        for(j=1; j<=m; j++){
            cin >> map[i][j];
            c+=map[i][j];
        }
    }

    bfs(1, 1);

    int ans=0;
    while(c){
        ans++;

        // for(i=1; i<=n; i++){
        //     for(j=1; j<=m; j++)
        //         cout << map[i][j] << " ";
        //         cout << endl;
        // }
        // cout << endl;

        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(map[i][j]==1){
                    int air=0;
                    for(int k=0; k<4; k++){
                        if(map[i+xx[k]][j+yy[k]]==2) air++;
                    }
                    if(air>=2){
                        map[i][j]=3;
                        c--;
                    }
                }
            }
        }

        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(map[i][j]==3){
                    map[i][j]=2;
                    bfs(i, j);
                }
            }
        }
    }

    cout << ans;

    return 0;
}