#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<climits>
using namespace std;

struct edge{
    int u,v;
    int w;
};

int n,k;
vector<pair<int,int>> adj[100];
int unused[100];

void prim(int k){
    vector<edge> mst;
    int d=0;
    unused[k]=1;
    while (mst.size()<n-1){
        int dmin=INT_MAX;
        int X,Y;
        for (int i=1;i<=n;i++){
            if (unused[i]==1){
                for (auto x : adj[i]){
                    if(unused[x.first]==0 && x.second<dmin){
                        dmin = x.second;
                        X=x.first;
                        Y=i;
                    }
                }
            }
        }
        unused[X]=1;
        d+=dmin;
        if (X>Y) swap(X,Y);
        mst.push_back({X,Y,dmin});
    }
    if (mst.size()!=n-1){
        cout<<"Do thi khong lien thong";
    }
    else {
        cout<<"dH ="<<d<<endl;
        for (auto x : mst){
            cout << x.u <<" "<<x.v<<endl;
        }
    }
}


int main(){
    cin >> n;
    cin >> k;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x!=0) adj[i].push_back({j,x});
        }
    }
    memset(unused,0,sizeof(int));
    prim(k);
}
