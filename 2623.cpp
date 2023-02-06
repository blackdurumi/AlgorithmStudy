#include<iostream>
#include<vector>
#include<queue>
#define N 1005

using namespace std;

int n, m, pre[N], check[N];
vector<int> ans, seq[N];
queue<int> q;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int i, j, l, a, b;
    cin >> n >> m;
    for(i=1; i<=m; i++){
        cin >> l >> a;
        for(j=2; j<=l; j++){
            cin >> b;
            seq[a].push_back(b);
            pre[b]++;
            a=b;
        }
    }

    for(i=1; i<=n; i++){
        if(pre[i]==0) q.push(i);
    }

    while(!q.empty())
    {
        int head = q.front();
        check[head]=1;
        q.pop();
        ans.push_back(head);

        for(auto i: seq[head]){
            if(check[i]) continue;
            pre[i]--;
            if(pre[i]==0) q.push(i);
        }
    }

    if(ans.size()<n){
        cout << 0;
        return 0;
    }
    for(auto i: ans) cout << i << endl;

    return 0;
}