#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005

using namespace std;

typedef pair<int, int> pii;

int v, check[N], ans;
vector<pii> map[N];

int dfs(int index)
{
    int i;
    vector<int> children;

    check[index]=1;
    for(i=0; i<map[index].size(); i++){
        if(check[map[index][i].first]) continue;
        check[map[index][i].first]=1;

        int child = dfs(map[index][i].first);
        children.push_back(child+map[index][i].second);
    }

    sort(children.begin(), children.end());
    reverse(children.begin(), children.end());

    if(children.size()==0) return 0;

    if(children.size()==1) ans = max(ans, children[0]);
    if(children.size()>=2) ans = max(ans, children[0]+children[1]);
    return children[0];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, a, b, c;
    cin >> v;
    for(i=1; i<=v; i++){
        cin >> a;
        cin >> b;
        while(b!=-1){
            cin >> c;
            map[a].push_back({b, c});
            cin >> b;
        }
    }

    dfs(1);

    cout << ans;

    return 0;
}