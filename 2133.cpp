#include<iostream>
#define N 35

using namespace std;

int n, d[N];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;

    cin >> n;
    d[0] = 1;
    d[2] = 3;
    for(i=4; i<=n; i+=2){
        for(j=0; j<i; j+=2){
            d[i] += d[j] * 2;
        }
        d[i] += d[i-2];
    }

    cout << d[n];

    return 0;
}