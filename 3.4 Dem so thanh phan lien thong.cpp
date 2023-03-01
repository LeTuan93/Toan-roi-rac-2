#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int unused[15];
int n;
vector<vector<int>> v(15,vector<int>(1,0));
void dfs(int i){
    unused[i]=1;
    for (auto x: v[i]){
        if (unused[x]==0) {
            dfs(x);
        }
    }
}

int tplienthong(){
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (unused[i]==0){
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main(){
    cin >> n;
    int x;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> x;
            if (x==1) v[i].push_back(j);
        }
    }
    memset(unused,0,sizeof(int));
    cout<<tplienthong();
}
