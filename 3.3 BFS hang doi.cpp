#include<bits/stdc++.h>
using namespace std;

int n;
queue<int> q;
int unused[100];
vector<int> kq;
vector<vector<int>> v(15,vector<int>(1,0));
void bfs(int i){
    unused[i]=1;
    q.push(i);
    int s=q.front();
    unused[s]=1;
    while (q.size()!=0){
        s=q.front();
        if (kq.size()!=n) kq.push_back(s);
        q.pop();
        for (auto x: v[s]){
            if (unused[x]==0 && x!=0){
                unused[x]=1;
                q.push(x);
            }
        }
    }
}




int main(){
    cin >> n;
    int a[n+5][n+5];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j]==1) v[i].push_back(j);
        }
    }
    memset(unused,0,sizeof(int));
    bfs(1);
    for (auto x:kq){
        cout<<x<<" ";
    }
}
