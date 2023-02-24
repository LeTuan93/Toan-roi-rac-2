#include<bits/stdc++.h>
using namespace std;

int unused[100];
int n;
vector<vector<int>> v (10,vector<int>(1,0));
void dfs(int i){
    cout<<i<<" ";
    unused[i]=1;
    for (auto x: v[i]){
        if (unused[x]==0 && x!=0) dfs(x);
    }
}


int main(){
    int n;
    cin >> n;
    int a[n+5][n+5];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]==1) v[i].push_back(j);
        }
    }
    memset(unused,0,sizeof(int));
    dfs(1);
}
