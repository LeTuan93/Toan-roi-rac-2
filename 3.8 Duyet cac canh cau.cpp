// Lưu ý code này có thể AC tuy nhiên code này chỉ đúng khi ma trận nhập vào là đồ thị có số thành phần liên thông là 1
// để đúng trong mọi trường hợp vui lòng tham khảo file code "Dinh tru canh cau.cpp" đã được cập nhật trong Repos Toan-roi-rac-2 
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<algorithm>
#include<set>
using namespace std;

vector<int> adj[30];
int unused[30];
stack<int> st;
int dfs(int j,int i,int x){
    for (int i=0;i<30;i++) unused[i]=0;
    auto it = find(adj[i].begin(),adj[i].end(),x);
    if (it!=adj[i].end()){
        adj[i].erase(it);
        adj[i].insert(it,-1);
    }
    set<int> se;
    st.push(j);
    while(st.size()!=0){
        int s=st.top();
        se.insert(s);
        st.pop();
        for (auto k:adj[s]){
            if (k!=-1){
                if (unused[k]==0){
                    unused[k]=1;
                    st.push(s);
                    st.push(k);
                    break;
                }
            }
        }
    }
    adj[i].erase(it);
    adj[i].insert(it,x);
    return se.size();
}
int a[30][30];
void duyetCau(int n){
    for (int i=1;i<=n;i++){
        for (auto x: adj[i]){
            if (a[i][x]==1 && dfs(1,i,x)!=n){
                cout<<i<<" "<<x<<endl;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            cin >> a[i][j];
            if (a[i][j] == 1) adj[i].push_back(j);
        }
    }
    duyetCau(n);
    
}
