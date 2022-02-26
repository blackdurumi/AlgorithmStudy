#include<iostream>
#include<deque>
#define N 5000005

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i, l, arr[N];
    deque<pair<int, int>> deq;
    cin >> n >> l;

    for(i=0; i<n; i++)
        cin >> arr[i];

    for(i=0; i<n; i++){
        if(!deq.empty() && deq.front().second<=i-l) deq.pop_front();
        while(!deq.empty() && deq.back().first>arr[i]) deq.pop_back();
        deq.push_back(make_pair(arr[i], i));

        cout << deq.front().first << " ";
    }

    return 0;
}