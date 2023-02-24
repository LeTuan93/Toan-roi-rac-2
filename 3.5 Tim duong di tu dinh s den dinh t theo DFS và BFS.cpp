#include<bits/stdc++.h>
using namespace std;

int n;
int unused[15];
int before[15];
vector<int> adj[15];
stack<int> st;
void dfs(int i){
    st.push(i);
    unused[i]=1;
    while (st.size()!=0){
        int s = st.top();
        st.pop();
        for (int x: adj[s]){
            if (unused[x]==0){
                st.push(s);
                st.push(x);
                unused[x]=1;
                before[x]=s;
                break;
            }
        }
    }
}

queue<int> q;
int unused1[15];
int before1[15];
void bfs(int i){
    q.push(i);
    unused1[i]=1;
    while (q.size()!=0){
        int s=q.front();
        q.pop();
        for (auto x : adj[s]){
            if (unused1[x]==0){
                unused1[x]=1;
                q.push(x);
                before1[x]=s;
            }
        }
    }
}

int main(){
    cin >> n;
    int a[n+3][n+3];
    int s,t;
    cin >> s >>t;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x == 1 ) adj[i].push_back(j);
        }
    }
    memset(unused,0,sizeof(int));
    memset(before,0,sizeof(int));
    dfs(s);
    if (before[t]==0) {
        cout<<"no path";
        return 0;
    }
    else {
        cout<<"DFS path:";
        int tmp =t;
        while (1){
            cout<<tmp<<" ";
            if (tmp==s) break;
            tmp=before[tmp];
        }
        cout<<endl;
        memset(unused1,0,sizeof(int));
        memset(before1,0,sizeof(int));
        bfs(s);
        cout<<"BFS path:";
        tmp =t;
        while (1){
            cout<<tmp<<" ";
            if (tmp==s) break;
            tmp=before1[tmp];
        }
    }
}
