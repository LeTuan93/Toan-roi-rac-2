#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int maxn = 100001;
int n;
vector<pair<int,int>> adj[maxn];
int pre[maxn];
void dijkstra(int s,int t){
	int t1=t;
	vector<long long> d(n+1,INF);
	d[s]=0;
	pre[s]=s;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	q.push({0,s});
	while (q.size()!=0){
		pair<int,int>   x = q.top();
		q.pop();
		int kc = x.first;
		int u = x.second;
		if (kc > d[u]) continue;
		for (auto it : adj[u]){
			int w= it.second;
			int v=it.first;
			if (d[v]>d[u]+w){
				d[v]= d[u]+w;
				pre[v]=u;
				q.push({d[v],v});
			}
		}
	}
	vector<int> path;
	while (1){
		path.push_back(t1);
		if (t1==s || t1==0) break;
		t1 = pre[t1];
	}
	if (d[t]==INF) cout<<"K/c "<<s<<" -> "<<t<<" = "<<"INF"<<";      ";
	else {
		cout<<"K/c "<<s<<" -> "<<t<<" = "<<d[t]<<";      ";
		for (int i=0;i<path.size();i++){
			if (d[t]!=INF) cout<<path[i];
			else cout<<"INF";
			if (i!=path.size()-1) cout<<" <- ";
		}
	}
}

int main(){
	cin >> n;
	int s;
	cin >> s ;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin >> x;
			if (x!=0) adj[i].push_back({j,x});
		}
	}
	for (int t=1;t<=n;t++){
		dijkstra(s,t);
		if (s==t) cout<<" <- "<<t;
		cout<<endl;
	}
}
