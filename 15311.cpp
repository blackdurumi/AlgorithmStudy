#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i;
    cin >> n;
    cout << 1000+n/1000 << endl;
    for(i=1; i<=1000; i++) cout << 1 << " ";
    for(i=1; i<=n/1000; i++) cout << 1000 << " ";

    return 0;
}