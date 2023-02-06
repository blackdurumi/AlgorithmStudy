#include<iostream>
#define N 100005

using namespace std;

int n, m, a1, a2, arr[N], st[N*3];

int make_tree(int left, int right, int index){
    if(left==right) return st[index] = arr[left]%2;

    int mid=(left+right)/2;
    return st[index] = make_tree(left, mid, index*2) + make_tree(mid+1, right, index*2+1);
}

int update_tree(int left, int right, int index)
{
    if(a1<left || right<a1) return st[index];
    if(left==right) return st[index] = a2%2;

    int mid=(left+right)/2;
    return st[index] = update_tree(left, mid, index*2) + update_tree(mid+1, right, index*2+1);
}

int get_tree(int left, int right, int index)
{
    if(a2<left || right<a1) return 0;
    if(a1<=left && right<=a2) return st[index];

    int mid=(left+right)/2;
    return get_tree(left, mid, index*2) + get_tree(mid+1, right, index*2+1);
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
        cin >> c >> a1 >> a2;
        if(c==1) update_tree(1, n, 1);
        if(c==2) printf("%d\n", a2-a1+1-get_tree(1, n, 1));
        if(c==3) printf("%d\n", get_tree(1, n, 1));
    }

    return 0;
}