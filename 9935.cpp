#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int i, j;
    vector<char> v;
    string str, target;
    cin >> str >> target;

    for(i=0; i<str.size(); i++){
        v.push_back(str[i]);
        if(v.size()>=target.length()){
            bool exit=false;
            for(j=0; j<target.length(); j++){
                if(target[j]!=v[v.size()-target.length()+j]){
                    exit=true;
                    break;
                }
            }

            if(exit) continue;

            for(j=0; j<target.length(); j++) v.pop_back();
        }
    }

    string ans(v.begin(), v.end());
    if(v.size()==0) ans="FRULA";
    cout << ans;
    
    return 0;
}