#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<algorithm>
#define N 100005

using namespace std;

vector<int> map[N];
bool check[N];
int d[N][20];

int fill(int index, int color)
{
    int i, j, ret=0;
    if(d[index][color]!=-1) return d[index][color];

    check[index]=true;
    for(i=0; i<map[index].size(); i++){
        if(check[map[index][i]]) continue;

        int cand=INT_MAX;
        for(j=1; j<=18; j++){
            if(j==color) continue;
            cand = min(cand, fill(map[index][i], j));
        }

        ret += cand;
    }
    check[index]=false;

    return d[index][color]=ret+color;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i;
    cin >> n;
    for(i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    memset(d, -1, sizeof(d));

    int ans=INT_MAX;
    for(i=1; i<=18; i++) ans=min(ans, fill(1, i));

    cout << ans;

    return 0;
}