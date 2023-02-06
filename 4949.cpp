#include<iostream>
#include<string>
#include<stack>
#define N 105

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string str;
    int i;
    getline(cin, str);
    
    stack<char> st;
    while(str.compare(".")){
        bool ans = true;
        while(!st.empty()) st.pop();
        for(i=0; i<str.length(); i++){
            if(str[i]=='(' || str[i]=='[') st.push(str[i]);
            else if(str[i]==')' || str[i]==']'){
                if(!st.empty() && st.top()=='(' && str[i]==')') st.pop();
                else if(!st.empty() && st.top()=='[' && str[i]==']') st.pop();
                else{
                    ans = false;
                    break;
                }
            }
        }

        if(ans && st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;

        getline(cin, str);
    }

    return 0;
}