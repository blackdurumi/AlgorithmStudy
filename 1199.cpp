#include<iostream>
#define N 1005

using namespace std;

int map[N][N], n, lc[N];

void dfs(int index)
{
    int i;
    for(i=1; i<=n; i++){
        while(map[index][i]){
            map[index][i]--;
            map[i][index]--;
            dfs(i);
        }
    }
    printf("%d ", index);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> map[i][j];
            lc[i]+=map[i][j];
            lc[j]+=map[i][j];
        }
    }
    for(i=1; i<=n; i++){
        lc[i]/=2;
        if(lc[i]%2){
            printf("-1");
            return 0;
        }
    }

    dfs(1);

    return 0;
}