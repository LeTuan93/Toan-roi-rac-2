#include<bits/stdc++.h>
using namespace std;

int unused[10];
int n;
vector<int> kq;
vector<vector<int>> v(10,vector<int>(1,0));
stack<int> st;
map<int,int> mp;
void dfs(int i,int n){
    st.push(i);
    unused[i]=1;
    while (st.size()!=0){
        int s=st.top();
        if (kq.size()!=n && mp[s]==0){
            kq.push_back(s);
            mp[s]++;
        }
        st.pop();
        for (int x : v[s]){
            if (unused[x]==0 && x!=0){
                unused[x]=1;
                st.push(s);
                st.push(x);
                break;
            }
        }
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
    dfs(1,n);
    for (auto x:kq){
        cout<<x<<" ";
    }
}
