#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<long long> a, b, c, d, ab, cd;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    long long n, i, j, ans=0;

    cin >> n;
    long long x;
    for(i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
        cin >> x;
        b.push_back(x);
        cin >> x;
        c.push_back(x);
        cin >> x;
        d.push_back(x);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            ab.push_back(a[i]+b[j]);
            cd.push_back(c[i]+d[j]);
        }
    }

    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    for(i=0; i<ab.size(); i++){
        long long key = ab[i]*(-1);
        long long aa=0;

        long long l=0, r=cd.size()-1;
        while(l<=r){
            long long mid = (l+r)/2;
            if(cd[mid]==key){
                aa++;
                long long k=0;
                while(mid+(++k)<cd.size() && key==cd[mid+k]) aa++;
                k=0;
                while(mid-(++k)>=0 && key==cd[mid-k]) aa++;
                break;
            }

            if(cd[mid]>key) r=mid-1;
            else if(cd[mid]<key) l=mid+1;
        }

        ans+=aa;
        while(i<ab.size()-1 && ab[i]==ab[i+1]){
            ans+=aa;
            i++;
        }
    }

    cout << ans;

    return 0;
}