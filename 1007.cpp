#include<iostream>
#include<cmath>
#include<climits> 
#include<algorithm>
#define N 25

using namespace std;

typedef pair<int, int> pii;

pii xy[N];
int n, check[N];
double ans;


double dist(pii a){
    return sqrt(pow(a.first, 2)+pow(a.second, 2));
}

double vec_sum(){
    int i;
    pii candi;
    for(i=1; i<=n; i++){
        if(check[i]){
            candi.first += xy[i].first;
            candi.second += xy[i].second;
        }
        else{
            candi.first -= xy[i].first;
            candi.second -= xy[i].second;
        }
    }

    return dist(candi);
}

void dfs(int s, int c){
    if(c==n/2){
        ans = min(ans, vec_sum());
        return;
    }

    int i;
    for(i=s; i<=n; i++){
        if(check[i]) continue;
        check[i]=1;
        dfs(i+1, c+1);
        check[i]=0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t, i, j;

    cin >> t;
    for(int tc=0; tc<t; tc++){
        ans = __DBL_MAX__;
        cin >> n;
        int a, b;
        for(i=1; i<=n; i++){
            cin >> a >> b;
            xy[i] = make_pair(a, b); 
        }

        dfs(1, 0);

        printf("%f\n", ans);
    }

    return 0;
}