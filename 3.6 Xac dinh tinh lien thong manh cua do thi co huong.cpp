#include<iostream>
#include<vector>
#include<cstring>
#include<set>
#include<stack>
using namespace std;

vector<int> adj[15];
int unused[15];

stack<int> st;
int dfs(int i){
    for (int i=0;i<15;i++){
        unused[i]=0;    
    }
    set<int> se;
    int maz = INT_MIN;
    st.push(i);
    unused[i]=1;
    while (st.size()!=0){
        se.insert(st.top());
        int s=st.top();
        st.pop();
        for (auto x: adj[s]){
            if (unused[x]==0){
                unused[x]=1;
                st.push(s);
                st.push(x);
                break;
            }
        }
    }
    return se.size();
}

bool checkStrongConnected(int n){
    memset(unused,0,sizeof(int));
    for (int i=1;i<=n;i++){
        if (dfs(i)!=n){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x == 1) adj[i].push_back(j);
            
        }
    }
    if (checkStrongConnected(n)==true) cout<<"strongly connected";
    else cout<<"not strongly connected";
}
