#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<stack>
#define N 1005

using namespace std;

typedef pair<int, int> pii;

int n, d[N], p[N];
vector<pii> bus[N];

priority_queue<pii> q;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, m, a, b, c, s, e;
    cin >> n >> m;
    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }

    cin >> s >> e;
    for(i=1; i<=n; i++) p[i]=i;
    memset(d, -1, sizeof(d));
    d[s]=0;
    q.push({s, 0});

    while(!q.empty()){
        pii head = q.top();
        q.pop();
        
        if(d[head.first]<-head.second) continue;
        for(auto i : bus[head.first]){
            if(d[i.first]==-1 || d[i.first]>-head.second+i.second){
                d[i.first]=-head.second+i.second;
                p[i.first]=head.first;
                q.push({i.first, -d[i.first]});
            }
        }
    }

    cout << d[e] << endl;

    stack<int> route;
    route.push(e);
    while(route.top()!=s){
        route.push(p[route.top()]);
    }

    cout << route.size() << endl;
    while(!route.empty()){
        cout << route.top() << " ";
        route.pop();
    }

    return 0;
}