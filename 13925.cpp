#include<iostream>
#define N 100005
#define MOD 1000000007

using namespace std;

long long arr[N], st[N*3];
pair<long long, long long> pst[N*3];

void build_tree(int left, int right, int index)
{
    if(left==right){
        st[index]=arr[left]%MOD;
        pst[index]=make_pair(1, 0);
        return;
    }

    int mid=(left+right)/2;
    build_tree(left, mid, index*2);
    build_tree(mid+1, right, index*2+1);

    st[index]=(st[index*2]+st[index*2+1])%MOD;
    pst[index]=make_pair(1, 0);
}

void prop(int left, int right, int index)
{
    if(pst[index].first==1 && pst[index].second==0) return;

    st[index] = (st[index]*pst[index].first+pst[index].second*(right-left+1))%MOD;

    if(left<right){
        pst[index*2].first=(pst[index*2].first*pst[index].first)%MOD;
        pst[index*2].second=(pst[index*2].second*pst[index].first+pst[index].second)%MOD;
        pst[index*2+1].first=(pst[index*2+1].first*pst[index].first)%MOD;
        pst[index*2+1].second=(pst[index*2+1].second*pst[index].first+pst[index].second)%MOD;
    }
    pst[index]=make_pair(1, 0);
}

void update(int left, int right, int index, int a, int b, int c, int d)
{
    prop(left, right, index);
    if(left>c || right<b) return;
    if(b<=left && right<=c){
        if(a==1) pst[index]=make_pair(1, d);
        else if(a==2) pst[index]=make_pair(d, 0);
        else pst[index]=make_pair(0, d);
        prop(left, right, index);
        return;
    }

    int mid=(left+right)/2;
    update(left, mid, index*2, a, b, c, d);
    update(mid+1, right, index*2+1, a, b, c, d);

    st[index]=(st[index*2]+st[index*2+1])%MOD;
}

long long print(int left, int right, int index, int b, int c)
{
    prop(left, right, index);
    if(left>c || right<b) return 0;
    if(b<=left && right<=c) return st[index];

    int mid=(left+right)/2;
    return (print(left, mid, index*2, b, c)+print(mid+1, right, index*2+1, b, c))%MOD;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    build_tree(1, n, 1);

    cin >> m;
    for(i=0; i<m; i++){
        int a, b, c, d;
        cin >> a;
        if(a==4){
            cin >> b >> c;
            printf("%lld\n", print(1, n, 1, b, c));
        }
        else{
            cin >> b >> c >> d;
            update(1, n, 1, a, b, c, d%MOD);
        }
    }

    return 0;
}