#include<iostream>
#include<vector>
#include<algorithm>
#define N 1005

using namespace std;

int n;
vector<string> tree[N];

bool compare(vector<string> a, vector<string> b){
    for(int idx=0; ; idx++){
        if(idx>=a.size()) return true;
        if(idx>=b.size()) return false;

        if(a[idx].compare(b[idx])!=0) return a[idx].compare(b[idx])<0;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    cin >> n;
    for(i=1; i<=n; i++){
        int k;
        cin >> k;
        for(j=1; j<=k; j++){
            string str;
            cin >> str;
            tree[i].push_back(str);
        }
    }

    sort(tree+1, tree+n+1 ,compare);

    for(j=0; j<tree[1].size(); j++){
        for(int k=0; k<j; k++) cout << "--";
        cout << tree[1][j] << endl;
    }
    for(i=2; i<=n; i++){
        int s=0;
        while(tree[i][s].compare(tree[i-1][s])==0) s++;
        if(s==tree[i-1].size()) s=0;

        for(j=s; j<tree[i].size(); j++){
            for(int k=0; k<j; k++) cout << "--";
            cout << tree[i][j] << endl;
        }
    }

    return 0;
}