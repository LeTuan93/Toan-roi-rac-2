#include<iostream>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;

int n,m;
set<int> adj[30];

void euler(int i){
    vector<int > eu;
    stack<int> st;
    st.push(i);
    while (st.size()!=0){
        int x = st.top();
        if (adj[x].size()!=0){
            int y=*adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            st.pop();
            eu.push_back(x);
        }
    }
    reverse(begin(eu),end(eu));
    for (int x : eu){
        cout << x << " ";
    }
}

int main(){
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x==1) adj[i].insert(j);
        }
    }
    euler(m);
    
}
