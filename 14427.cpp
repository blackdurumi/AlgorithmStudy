#include<iostream>
#include<algorithm>
#include<climits>
#define N 100005

using namespace std;

int n, m, arr[N], st[N*3], a1, a2;

int make_tree(int left, int right, int index)
{
    if(left==right) return st[index]=arr[left];

    int mid=(left+right)/2;
    return st[index] = min(make_tree(left, mid, index*2), make_tree(mid+1, right, index*2+1));
}

int update_tree(int left, int right, int index)
{
    if(a1<left || right<a1) return st[index];
    if(left==right) return st[index]=a2;

    int mid=(left+right)/2;
    return st[index] = min(update_tree(left, mid, index*2), update_tree(mid+1, right, index*2+1));
}

int get_tree(int left, int right, int index){
    if(left==right) return left;

    int mid=(left+right)/2;
    return (st[1]==st[index*2]) ? get_tree(left, mid, index*2) : get_tree(mid+1, right, index*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, c;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    make_tree(1, n, 1);
    cin >> m;

    for(i=1; i<=m; i++){
        cin >> c;
        if(c==1){
            cin >> a1 >> a2;
            update_tree(1, n, 1);
        }
        if(c==2) printf("%d\n", get_tree(1, n, 1));
    }

    return 0;
}