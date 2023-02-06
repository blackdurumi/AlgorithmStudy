#include<iostream>
#include<cstring>
#define N 100005

using namespace std;

int n, m, st[N*10], target, exist[N*2], idx[N];

int make_tree(int left, int right, int index)
{
    if(left==right) return st[index] = exist[left];

    int mid = (left+right)/2;
    return st[index] = make_tree(left, mid, index*2) + make_tree(mid+1, right, index*2+1);
}

int get_tree(int left, int right, int index, int goal)
{
    if(right<goal) return st[index];
    if(goal<=left) return 0;

    int mid = (left+right)/2;
    return get_tree(left, mid, index*2, goal) + get_tree(mid+1, right, index*2+1, goal);
}

int update_tree(int left, int right, int index, int goal)
{
    if(goal<left || right<goal) return st[index];
    if(left==right) return st[index] = exist[left];

    int mid = (left+right)/2;
    return st[index] = update_tree(left, mid, index*2, goal) + update_tree(mid+1, right, index*2+1, goal);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t, tc, i;
    cin >> tc;
    for(t=0; t<tc; t++){
        cin >> n >> m;
        memset(exist, 0, sizeof(exist));
        for(i=1; i<=n; i++){
            exist[i+m-1] = 1;
            idx[i] = i+m-1;
        }
        make_tree(0, n+m-1, 1);

        for(i=1; i<=m; i++){
            cin >> target;

            cout << get_tree(0, n+m-1, 1, idx[target]) << " ";
            
            if(i==m) break;
            exist[idx[target]] = 0;
            update_tree(0, n+m-1, 1, idx[target]);
            idx[target] = m-i;
            exist[m-i] = 1;
            update_tree(0, n+m-1, 1, m-i);
        }
        printf("\n");
    }

    return 0;
}