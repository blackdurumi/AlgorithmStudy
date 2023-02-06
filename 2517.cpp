#include<iostream>
#include<vector>
#include<algorithm>
#define N 500005

using namespace std;

typedef vector<int> vi;

int n, arr[N], goal, srt[N], tree[N*3];

int get_tree(int left, int right, int index)
{
    if(right<1 || left>goal) return 0;
    if(1<=left && right<=goal) return tree[index];
    
    int mid=(left+right)/2;
    return get_tree(left, mid, index*2) + get_tree(mid+1, right, index*2+1);
}

int update_tree(int left, int right, int index)
{
    if(right<goal || left>goal) return tree[index];
    if(left==right) return ++tree[index];

    int mid=(left+right)/2;
    return tree[index] = update_tree(left, mid, index*2) + update_tree(mid+1, right, index*2+1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i;

    cin >> n;
    for(i=1; i<=n; i++){
        cin >> arr[i];
        srt[i]=arr[i];
    }
    sort(srt+1, srt+n+1);
    for(i=1; i<=n; i++) arr[i]=lower_bound(srt+1, srt+n+1, arr[i])-srt;

    for(i=1; i<=n; i++){
        goal=arr[i]-1;
        int ret = get_tree(1, n, 1);
        printf("%d\n", i-ret);
        goal=arr[i];
        update_tree(1, n, 1);
    }

    return 0;
}