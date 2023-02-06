#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;

int n, d;

vector<pii> list;

struct comp{
    bool operator()(pii a, pii b){
        if(a.first==b.first) return a.second>b.second;
        return a.first>b.first;
    }
};

bool compare(pii a, pii b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

priority_queue<pii, vector<pii>, comp> pq;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, a, b;
    int ans = 0;

    cin >> n;
    for(i=1; i<=n; i++){
        cin >> a >> b;
        if(a>b) list.push_back({b, a});
        else list.push_back({a, b});
    }
    cin >> d;

    sort(list.begin(), list.end(), compare);

    for(i=0; i<n; i++){
        if(list[i].second-list[i].first>d) continue;

        pq.push(list[i]);
        while(!pq.empty() && pq.top().first<list[i].second-d) pq.pop();

        ans = max(ans, int(pq.size()));
    }

    cout << ans;

    return 0;
}