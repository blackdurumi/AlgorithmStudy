#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n;

priority_queue<int> pq;
vector<pii> arr;

bool comp(const pii &l, const pii &r)
{
    return l.first<r.first;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, i, ans=0, t;
    cin >> n;
    arr.resize(n);
    for (i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), comp);

    for(i=arr[n-1].first; i>=1; i--){
        while(arr[arr.size()-1].first==i){
            pq.push(arr[arr.size()-1].second);
            arr.pop_back();
        }

        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}