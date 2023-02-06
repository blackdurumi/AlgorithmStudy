#include<iostream>
#include<queue>
#include<vector>
#define N 1005
#define INF 1000000000

using namespace std;

int n, m, s, e, dist[N];

typedef pair<int, int> pii;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pii>> qq;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i, a, b, c;
	scanf("%d %d", &n, &m);
	vector<vector<pair<int, int>>> graph(n+5);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &s, &e);
	
	for(i=1; i<=n; i++)
		dist[i]=INF;
	dist[s]=0;
	
	qq.push(make_pair(s, 0));
	
	while(!qq.empty()){
		pair<int, int> head=qq.top();
		qq.pop();
		
        if(dist[head.first]<head.second) continue;
		for(i=0; i<graph[head.first].size(); i++){
			if(dist[graph[head.first][i].first]>head.second+graph[head.first][i].second){
				dist[graph[head.first][i].first]=head.second+graph[head.first][i].second;
				qq.push(make_pair(graph[head.first][i].first, dist[graph[head.first][i].first]));
			}
		}
	}
	
	printf("%d\n", dist[e]);
	
	return 0;
}