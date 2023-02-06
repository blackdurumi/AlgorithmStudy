#include<iostream>
#define N 105

using namespace std;

struct shark{
    int s, d, z;
};

int r, c, m;
int xx[5]={0, -1, 1, 0, 0};
int yy[5]={0, 0, 0, 1, -1};
shark map[N][N], nxt[N][N];

void replace()
{
    int i, j;
    shark blank;
    blank.s=0, blank.d=0, blank.z=0;
    for(i=1; i<=r; i++){
        for(j=1; j<=c; j++){
            map[i][j]=nxt[i][j];
            nxt[i][j]=blank;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    int a1, a2, a3, a4, a5;
    cin >> r >> c >> m;
    for(i=1; i<=m; i++){
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        shark temp;
        temp.s = a3;
        temp.d = a4;
        temp.z = a5;
        map[a1][a2] = temp;
    }

    int ans=0;

    for(int t=1; t<=c; t++){
        for(i=1; i<=r; i++){
            if(map[i][t].d){
                ans+=map[i][t].z;

                shark blank;
                blank.s=0, blank.d=0, blank.z=0;
                map[i][t]=blank;
                break;
            }
        }

        if(t==c) continue;

        for(i=1; i<=r; i++){
            for(j=1; j<=c; j++){
                if(map[i][j].d){
                    int d = map[i][j].d;
                    int s = map[i][j].s;

                    int nx = i+xx[d]*s;
                    int ny = j+yy[d]*s;

                    while(nx<1 || nx>r){
                        d = 3-d;
                        if(nx<1) nx = 2-nx;
                        else nx = r*2-nx;
                    }
                    while(ny<1 || ny>c){
                        d = 7-d;
                        if(ny<1) ny = 2-ny;
                        else ny = c*2-ny;
                    }

                    if(!nxt[nx][ny].d || map[i][j].z>nxt[nx][ny].z){
                        nxt[nx][ny] = map[i][j];
                        nxt[nx][ny].d = d;
                    }
                }
            }
        }

        replace();
    }

    cout << ans;

    return 0;
}