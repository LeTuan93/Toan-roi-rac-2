//Lưu ý code này có thể AC tuy nhiên code này chỉ đúng khi ma trận nhập vào là đồ thị có số thành phần liên thông là 1, để đúng trong mọi trường hợp vui lòng tham khảo file code "Dinh tru canh cau.cpp" đã được cập nhật trong Repos Toan-roi-rac-2
#include<iostream>
#include<vector>
#include<cstring>
#include<stack>
#include<set>
using namespace std;

vector<int> adj[35];
int unused[35];


stack<int> st;
int dfs(int i,int x){
    for (int i=0;i<15;i++) unused[i]=0;
    unused[x]=1;
    st.push(i);
    set<int>se;
    while (st.size()!=0){
        int s=st.top();
        st.pop();
        for (auto x : adj[s]){
            if (unused[x]==0){
                unused[x]=1;
                st.push(s);
                st.push(x);
                se.insert(x);
                break;
            }
        }
    }
    return se.size();
}


void duyetDinhTru(int n){
    for(int i=1;i<=n;i++){
        if (dfs(1,i)!=n-1){
            cout<<i<<" ";
        }
    }
}


int main(){
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x==1) adj[i].push_back(j);
        }
    }
    duyetDinhTru(n);
}
