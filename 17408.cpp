#include<iostream>
#include<vector>
#include<algorithm>
#define N 100005

using namespace std;

int n, arr[N], a1, a2;
vector<int> st[N*3];

vector<int> make_tree(int left, int right, int index)
{
    if(left==right) return st[index] = vector<int>{arr[left], 0};

    int mid=(left+right)/2;
    make_tree(left, mid, index*2);
    make_tree(mid+1, right, index*2+1);

    reverse(st[index*2].begin(), st[index*2].end());
    reverse(st[index*2+1].begin(), st[index*2+1].end());

    merge(st[index*2].begin(), st[index*2].end(), st[index*2+1].begin(), st[index*2+1].end(), back_inserter(st[index]));
    reverse(st[index].begin(), st[index].end());
    st[index].resize(2);

    reverse(st[index*2].begin(), st[index*2].end());
    reverse(st[index*2+1].begin(), st[index*2+1].end());

    return st[index];
}

vector<int> update_tree(int left, int right, int index)
{
    if(a1<left || right<a1) return st[index];
    if(left==right) return st[index] = vector<int>{a2, 0};

    int mid=(left+right)/2;
    vector<int> l = update_tree(left, mid, index*2);
    vector<int> r = update_tree(mid+1, right, index*2+1);

    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    
    st[index] = vector<int>();
    merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(st[index]));
    reverse(st[index].begin(), st[index].end());
    st[index].resize(2);

    return st[index];
}

vector<int> get_tree(int left, int right, int index)
{
    if(a2<left || right<a1) return vector<int>();
    if(a1<=left && right<=a2) return st[index];

    int mid=(left+right)/2;
    vector<int> l = get_tree(left, mid, index*2);
    vector<int> r = get_tree(mid+1, right, index*2+1);

    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    
    vector<int> ret;
    merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(ret));
    reverse(ret.begin(), ret.end());
    ret.resize(2);

    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int m, c, i;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];
    make_tree(1, n, 1);

    cin >> m;
    for(i=1; i<=m; i++){
        cin >> c >> a1 >> a2;
        if(c==1) update_tree(1, n, 1);
        if(c==2){
            vector<int> res = get_tree(1, n, 1);
            printf("%d\n", res[0]+res[1]);
        }
    }

    return 0;
}