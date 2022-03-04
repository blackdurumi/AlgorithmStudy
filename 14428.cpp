#include<iostream>
#include<algorithm>
#include<climits>
#define N 100005

using namespace std;

int arr[N], st[N*3];

void make_tree(int left, int right, int index)
{
    if(left==right){
        st[index]=left;
        return;
    }

    int mid=(left+right)/2;
    make_tree(left, mid, index*2);
    make_tree(mid+1, right, index*2+1);

    st[index] = (arr[st[index*2]]>arr[st[index*2+1]]) ? st[index*2+1] : st[index*2];
}

void edit_tree(int left, int right, int index, int b, int c)
{
    if(left==right){
        arr[b]=c;
        return;
    }

    int mid=(left+right)/2;
    if(b<=mid) edit_tree(left, mid, index*2, b, c);
    else edit_tree(mid+1, right, index*2+1, b, c);

    st[index] = (arr[st[index*2]]>arr[st[index*2+1]]) ? st[index*2+1] : st[index*2];
}

int query(int left, int right, int index, int b, int c)
{
    if(c<left || right<b) return 0;
    if(b<=left && right<=c) return st[index];

    int mid=(left+right)/2;
    int l = query(left, mid, index*2, b, c);
    int r = query(mid+1, right, index*2+1, b, c);
    return (arr[l]>arr[r]) ? r : l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i, t;
    cin >> n;
    for(i=1; i<=n; i++) cin >> arr[i];

    make_tree(1, n, 1);
    arr[0]=INT_MAX;

    cin >> t;
    for(i=0; i<t; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a==1) edit_tree(1, n, 1, b, c);
        else printf("%d\n", query(1, n, 1, b, c));
    }

    return 0;
}