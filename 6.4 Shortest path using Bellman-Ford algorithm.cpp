#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int a[100][100];
long long d[100];
int pre[100];
int n;
void Bellman_ford(int s){
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++){
		d[i]=a[s][i];
		pre[i]=s;
	}
//	for (int i=1;i<=n;i++){
//		cout<<d[i]<<","<<pre[i]<<" ";
//	}
//	cout<<endl;
	
	for (int k=1;k<=n-2;k++){
		for (int v=1 ;v<=n;v++){
			if (v == s) continue;
			for (int u=1;u<=n;u++){
				if (d[v]> d[u] + a[u][v]){
					d[v]=d[u]+ a[u][v];
					pre[v]=u;
				}
			}
		}
//		for (int i=1;i<=n;i++){
//			cout<<d[i]<<","<<pre[i]<<" ";
//		}
//		cout<<endl;
	}
}

int main(){
	cin >> n;
	int s;
	cin >> s;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin >> a[i][j];
			if (i==j){
				a[i][j]=0;
			}
			else if (a[i][j]==0){
				a[i][j]=1e9;
			}
		}
	}
	Bellman_ford(s);
	for (int i=1;i<=n;i++){
		cout<<"K/c "<<s<<" -> "<<i<<" = ";
		if (d[i]>=1e9 || d[i]==999999989) cout<<"INF"<<";        "<<endl;
		else {
			cout<<d[i]<<";        ";
			int i1=i;
			if (i1==s || d[i1]>=INF){
				if (d[i1] >=INF) cout<<"INF"<<" <- "; 
				else cout<<i1<<" <- ";
			}
			else{
				while (i1!=s){
					if (d[i1]>=INF) cout<<"INF"<<" <- "; 
					else cout<<i1<<" <- ";
					i1 = pre[i1];
				}
			}
			cout<<i1<<endl;
		}
	}
}
//5
//1
//0 1 0 0 3
//0 0 3 3 8
//0 0 0 1 -5
//0 0 2 0 0
//0 0 0 4 0

//9								
//3								
//0 7 0 9 4 0 0 0 0
//0 0 3 0 -4 0 0 0 0
//0 0 0 0 -8 0 -3 0 0
//0 0 0 0 0 0 0 -4 0
//0 0 0 5 0 2 0 3 0
//0 0 0 0 0 0 5 0 2
//0 0 0 0 0 0 0 0 -7
//0 0 0 0 0 -2 0 0 -3
//0 0 0 0 0 0 0 0 0

