#include<iostream>
#include<queue>
#define N 205

using namespace std;

int n, m, k, map[N][N], check[N][N][33];
int xx[12]={0, 0, 1, -1, -2, -2, -1, -1, 1, 1, 2, 2};
int yy[12]={1, -1, 0, 0, -1, 1, -2, 2, -2, 2, 1, -1};

typedef struct info{
    int x, y, jump, t;
    info(int x, int y, int jump, int t) : x(x), y(y), jump(jump), t(t) {}
} info;

queue<info> q;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> k >> m >> n;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)
            cin >> map[i][j];
    }

    int ans=-1;
    q.push(info(1, 1, k, 0));
    check[1][1][k]=1;
    while(!q.empty()){
        info head = q.front();
        q.pop();
        bool jump = head.jump;

        if(head.x==n && head.y==m){
            ans=head.t;
            break;
        }

        int end = (jump) ? 12 : 4;
        for(i=0; i<end; i++){
            int nx = head.x+xx[i];
            int ny = head.y+yy[i];

            if(nx<1 || ny<1 || nx>n || ny>m) continue;
            if(map[nx][ny]) continue;

            if(i>=4){
                if(check[nx][ny][head.jump-1]) continue;
                check[nx][ny][head.jump-1]=1;
                q.push(info(nx, ny, head.jump-1, head.t+1));
            }
            else{
                if(check[nx][ny][head.jump]) continue;
                check[nx][ny][head.jump]=1;
                q.push(info(nx, ny, head.jump, head.t+1));
            }
        }
    }

    cout << ans;

    return 0;
}