#include<iostream>
#include<deque>
#include<algorithm>
#define N 15

using namespace std;

deque<int> tree[N][N];
int n, year, a[N][N], nut[N][N];
int xx[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int yy[8]={-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int m, i, j;
    cin >> n >> m >> year;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> a[i][j];
            nut[i][j]=5;
        }
    }
    
    int a1, a2, a3;
    for(i=1; i<=m; i++){
        cin >> a1 >> a2 >> a3;
        tree[a1][a2].push_back(a3);
    }

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            sort(tree[i][j].begin(), tree[i][j].end());
    }

    for(int t=0; t<year; t++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                for(int k=0; k<tree[i][j].size(); k++){
                    if(nut[i][j]>=tree[i][j][k]) nut[i][j]-=tree[i][j][k]++;
                    else{
                        while(tree[i][j].size()>k){
                            nut[i][j]+=tree[i][j].back()/2;
                            tree[i][j].pop_back();
                        }
                        break;
                    }
                }
                nut[i][j]+=a[i][j];
            }
        }

        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                for(int k=0; k<tree[i][j].size(); k++){
                    if(tree[i][j][k]%5==0){
                        for(int l=0; l<8; l++){
                            int nx=i+xx[l];
                            int ny=j+yy[l];
                            if(nx<1 || ny<1 || nx>n || ny>n) continue;
                            tree[nx][ny].push_front(1);
                        }
                    }
                }
            }
        }
    }

    int ans=0;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            ans+=tree[i][j].size();
    }

    cout << ans;
    
    return 0;
}