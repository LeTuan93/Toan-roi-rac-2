#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,s;
vector<int> adj[30];
int unused[30];
int x[30];

void hmt(int k){
    for (auto y :adj[x[k-1]]){
        if (k == n+1 && y == s){
            for (int i=1;i<=n;i++) cout<<x[i]<<" ";
            cout<<s;
            cout<<endl;
        }
        else if (unused[y]==0){
            unused[y]=1;
            x[k]=y;
            hmt(k+1);
            unused[y]=0;
        }
    }
}

void hmtCircle(int v){
    for (int i=1;i<=n;i++) unused[i]=0;
    x[1]=v;
    unused[v]=1;
    hmt(2);
}
int main(){
    cin >> n >> s;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x==1) adj[i].push_back(j);
        }
    }
    hmtCircle(1);
}

