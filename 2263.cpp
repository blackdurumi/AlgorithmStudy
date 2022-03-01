#include<iostream>
#include<stack>
#define N 100005

using namespace std;

int in[N], post[N];

void dq(int a, int b, int c, int d)
{
    int i, p;

    for(i=a; i<=b; i++){
        if(in[i]==post[d])
            break;
    }
    cout << in[i] << " ";

    if(a==b && c==d) return;

    if(i!=a) dq(a, i-1, c, c+i-a-1);
    if(i!=b) dq(i+1, b, c+i-a, d-1);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i;
    cin >> n;
    for(i=1; i<=n; i++) cin >> in[i];
    for(i=1; i<=n; i++) cin >> post[i];

    dq(1, n, 1, n);

    return 0;
}