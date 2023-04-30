#include<bits/stdc++.h>
using namespace std;

const int INF=1e9;
int d[100][100];
int nex[100][100];
int a[100][100];
int n;

void floyd(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			d[i][j]=a[i][j];
			if (a[i][j]!=INF) nex[i][j]=j;
			else nex[i][j]=0;
		}
	}
	
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (d[i][j]> d[i][k]+d[k][j]){
					d[i][j]= d[i][k]+ d[k][j];
					nex[i][j]=nex[i][k];
				}
			}
		}
	}
}

void reconstruct_Path(int u , int v){
	vector<int> path;
	if (nex[u][v]==-1){
		cout<<"Khong co duong di tu"<<u<<" den "<<v;
	} else{
		path.push_back(u);
		while (u!=v){
			u = nex[u][v];
			path.push_back(u);
		}
		for (int i=0;i<path.size();i++){
			cout <<path[i];
			if (i!=path.size()-1) cout<<" -->   ";
		}
		cout<<endl;
	}
	
}
int main(){
	cin >> n;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cin >> a[i][j];
			if (i==j){
				a[i][j]=0;
			} else if (a[i][j]==0 ){
				a[i][j]=INF;
			}
		}
	}
	floyd();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			cout<<"K/c "<<i<<" -> "<<j<<" = "<<d[i][j]<<";   ";
				reconstruct_Path(i,j);
		}
		cout<<endl;
	}
}
//4
//0 0 -2 0
//4 0 3 0
//0 0 0 2
//0 -1 0 0
