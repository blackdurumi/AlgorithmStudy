#include<iostream>
#include<algorithm>
#define N 1050

using namespace std;

int n, map[N][N], a1, a2, a3, a4, tree[N*2][N*2];

int make_subtree(int tidx, int line, int left, int right, int index)
{
    if(left==right) return tree[tidx][index]=map[line][left];

    int mid=(left+right)/2;
    return tree[tidx][index]=make_subtree(tidx, line, left, mid, index*2) + make_subtree(tidx, line, mid+1, right, index*2+1);
}

void make_tree(int left, int right, int index)
{
    if(left==right){
        make_subtree(index, left, 1, n, 1);
        return;
    }

    int mid=(left+right)/2;
    make_tree(left, mid, index*2);
    make_tree(mid+1, right, index*2+1);
    for(int i=1; i<=n*2; i++) tree[index][i] = tree[index*2][i]+tree[index*2+1][i];
}

int update_subtree(int tidx, int left, int right, int index)
{
    if(a2<left || a2>right) return tree[tidx][index];
    if(left==right) return tree[tidx][index]=a3;

    int mid=(left+right)/2;

    return tree[tidx][index] = update_subtree(tidx, left, mid, index*2) + update_subtree(tidx, mid+1, right, index*2+1);
}

void update_tree(int left, int right, int index)
{
    if(a1<left || a1>right) return;
    if(left==right){
        update_subtree(index, 1, n, 1);
        return;
    }

    int mid=(left+right)/2;

    update_tree(left, mid, index*2);
    update_tree(mid+1, right, index*2+1);
    for(int i=1; i<=n*2; i++) tree[index][i] = tree[index*2][i] + tree[index*2+1][i];
}

int get_subtree(int line, int left, int right, int index)
{
    if(right<a2 || left>a4) return 0;
    if(a2<=left && right<=a4) return tree[line][index];

    int mid=(left+right)/2;

    return get_subtree(line, left, mid, index*2)+get_subtree(line, mid+1, right, index*2+1);
}

int get_tree(int left, int right, int index)
{
    if(right<a1 || left>a3) return 0;
    if(a1<=left && right<=a3) return get_subtree(index, 1, n, 1);
    int mid=(left+right)/2;
    return get_tree(left, mid, index*2)+get_tree(mid+1, right, index*2+1);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j, m, c;
    cin >> n >> m;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            cin >> map[i][j];
    }

    make_tree(1, n, 1);

    for(i=1; i<=m; i++){
        cin >> c;
        if(c==0){
            cin >> a1 >> a2 >> a3;
            update_tree(1, n, 1);
        }
        else{
            cin >> a1 >> a2 >> a3 >> a4;
            if(a1>a3) swap(a1, a3);
            if(a2>a4) swap(a2, a4);
            printf("%d\n", get_tree(1, n, 1));
        }
    }

    return 0;
}