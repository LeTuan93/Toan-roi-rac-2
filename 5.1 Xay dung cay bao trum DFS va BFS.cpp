#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int unused[100];
int n,k;
vector<int> adj[100];
vector<pair<int,int>> vp;

void dfs(int i){
    unused[i]=1;
    for (auto x: adj[i]){
        if (unused[x] == 0){
            int c=i;
            int c1=x;
            if (c>c1) swap(c,c1);
            vp.push_back({c,c1});
            dfs(x);
        }
    }
}
void CayBaoTrum_DFS(int i){
    for (int i=1;i<=n;i++) unused[i]=0;
    dfs(i);
    if (vp.size()<n-1){
        cout<<"Do thi khong lien thong";
    }
    else {
        for (auto x : vp){
            cout << x.first << " " << x.second << endl;
        }
    }
}
queue<int> q;
void CayBaoTrum_BFS(int i){
    for (int i=1;i<=n;i++) unused[i]=0;
     vector<pair<int,int>> T;
    q.push(i);
    unused[i]=1;
    while (q.size()!=0){
        int s = q.front();
        q.pop();
        for (auto x : adj[s]){
            if (unused[x]==0){
                unused[x]=1;
                int c=s;
                int c1=x;
                if (c>c1) swap(c,c1);;
                T.push_back({c,c1});
                q.push(x);
            }
        }
    }
    if (T.size()<n-1){
        cout<<"Do thi khong lien thong";
    }
    else{
        for (auto x : T){
            cout << x.first << " " << x.second << endl;
        }
    }
}

int main(){
    cin >> n >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x==1) adj[i].push_back(j);
        }
    }
    cout<<"DFS tree"<<endl;
    CayBaoTrum_DFS(k);
    cout<<"BFS tree"<<endl;
    CayBaoTrum_BFS(k);
}
