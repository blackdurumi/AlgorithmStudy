#include<iostream>
#include<algorithm>
#include<vector>
#define N 100005

using namespace std;

int n, m, a1, a2, a3, mi;
vector<int> st[N*3];

void make_tree(int left, int right, int index, int goal)
{
    if(goal<left || right<goal) return;
    mi = max(mi, index);
    st[index].push_back(a1);

    if(left==right) return;
    int mid=(left+right)/2;
    make_tree(left, mid, index*2, goal);
    make_tree(mid+1, right, index*2+1, goal);
}

int get_tree(int left, int right, int index)
{
    if(right<a1 || a2<left) return 0;
    if(a1<=left && right<=a2) return st[index].end() - upper_bound(st[index].begin(), st[index].end(), a3);
    
    int mid=(left+right)/2;
    return get_tree(left, mid, index*2) + get_tree(mid+1, right, index*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, a;
    cin >> n;
    for(i=1; i<=n; i++){
        cin >> a1;
        make_tree(1, n, 1, i);
    }

    for(i=1; i<=mi; i++){
        sort(st[i].begin(), st[i].end());
    }

    cin >> m;
    for(i=1; i<=m; i++){
        cin >> a1 >> a2 >> a3;
        printf("%d\n", get_tree(1, n, 1));
    }

    return 0;
}