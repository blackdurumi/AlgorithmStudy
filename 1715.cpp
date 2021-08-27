#include <iostream>
#include<queue>
#define N 100005

using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;

    cin >> n;
    for(i=1; i<=n; i++){
        int a;
        cin >> a;
        q.push(a);
    }

    while(q.size()>1){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();


        ans += a+b;
        if(q.empty()) break;
        q.push(a+b);
    }

    cout << ans;

    return 0;
}