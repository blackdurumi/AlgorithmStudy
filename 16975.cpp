#include<iostream>
#define N 1000005

using namespace std;

typedef long long ll;

int n, arr[N];
ll st[N*3], lazy[N*3];
int a1, a2, a3;

ll make_tree(int left, int right, int index)
{
    if(left==right) return st[index]=arr[left];

    int mid = (left+right)/2;
    return st[index] = make_tree(left, mid, index*2) + make_tree(mid+1, right, index*2+1);
}

ll add_tree(int left, int right, int index)
{
    if(right<a1 || a2<left) return st[index];
    if(a1<=left && right<=a2){
        if(left<right){
            lazy[index*2] += a3;
            lazy[index*2+1] += a3;
        }
        return st[index] += (right-left+1)*a3;
    }

    int mid = (left+right)/2;
    return st[index] = add_tree(left, mid, index*2) + add_tree(mid+1, right, index*2+1);
}

ll get_tree(int left, int right, int index)
{
    if(a1<left || right<a1) return 0;

    if(lazy[index]){
        st[index] += (right-left+1)*lazy[index];
        if(left<right){
            lazy[index*2] += lazy[index];
            lazy[index*2+1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if(left==right) return st[index];

    int mid = (left+right)/2;
    return get_tree(left, mid, index*2) + get_tree(mid+1, right, index*2+1);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    int i, m, q, c;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];

    make_tree(1, n, 1);

    cin >> m;
    for(q=0; q<m; q++){
        cin >> c;
        if(c==1){
            cin >> a1 >> a2 >> a3;
            add_tree(1, n, 1);
        }
        else{
            cin >> a1;
            printf("%lld\n", get_tree(1, n, 1));
        }
    }

    return 0;
}