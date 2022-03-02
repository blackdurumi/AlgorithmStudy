// #include<iostream>
// #include<stack>
// #include<algorithm>
// #define N 100005

// using namespace std;

// stack<pair<int, int>> st;

// int main()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int n, i, ans=0;
//     cin >> n;
//     for(i=1; i<=n; i++){
//         int a;
//         cin >> a;

//         if(!st.empty() && a<st.top().first){
//             while(!st.empty() && a<st.top().first){
//                 ans = max(ans, (i-st.top().second)*st.top().first);
//                 st.pop();
//             }
//         }
//         if(st.empty() || a>st.top().first) st.push(make_pair(a, i));
//     }

//     while(!st.empty()){
//         ans = max(ans, (n+1-st.top().second)*st.top().first);
//         st.pop();
//     }

//     cout << ans;

//     return 0;
// }
#include <stdio.h>
#define N 100005

typedef long long ll;

ll arr[N];

ll max(ll a, ll b)
{
	if(a>b) return a;
	return b;
}

ll f(int left, int right)
{
	if(left==right) return arr[left];
	int mid=(left+right)/2;
	ll ans=max(f(left, mid), f(mid+1, right));
	
	int a, b;
	a=mid;
	b=mid+1;
	ll top=arr[a]+arr[b]-max(arr[a], arr[b]);
	ans=max(ans, (b-a+1)*top);
	
	while(a>left || b<right){
		if((arr[a-1]>arr[b+1] && a!=left) || b==right){
			a--;
			top=top+arr[a]-max(top, arr[a]);
		}
		else{
			b++;
			top=top+arr[b]-max(top, arr[b]);
		}
		ans=max(ans, (b-a+1)*top);
	}
	
	return ans;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	
	int n, i;
	
    scanf("%d", &n);
    for(i=1; i<=n; i++)
        scanf("%lld", &arr[i]);
    arr[0]=0;
    arr[n+1]=0;
    
    printf("%lld\n", f(1, n));
	
	return 0;
}