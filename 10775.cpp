#include<iostream>
#define N 100005

using namespace std;

int n, pp, p, par[N];

int find(int index)
{
    if(par[index]==index) return index;

    return par[index]=find(par[index]);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;
    cin >> n >> pp;

    for(i=1; i<=n; i++)
    par[i]=i;

    for(i=1; i<=pp; i++){
        cin >> p;
        p=find(p);
        if(p==0) break;
        par[p]=p-1;
    }

    cout << i-1;

    return 0;
}