#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct edge{
    int u,v;
    int w;
};
int cnt=0;
int parent[100];
int sz[100];
int n;
vector<edge> vp;
void make_set(){
    for (int i=1;i<=n;i++) {
        parent[i]=i;
        sz[i]=1;
    }
}

int find(int v){
    if (v==parent[v]) return v;
    else return parent[v]=find(parent[v]);
}

bool Union(int x, int y){
    int a= find(x);
    int b = find(y);
    if (a == b) return false;
    if (sz[a]<sz[b]) swap(a,b);
    parent[b] = a;
    sz[a]+=sz[b];
    return true;
}

bool cmp(edge a, edge b){
    if (a.w == b.w) {
        if (a.u == b.u) return a.v<b.v;
        return a.u<b.u;
    }
    return  a.w< b.w;
}

void kruskal(){
    vector<edge> mst;
    int d=0;
    sort(vp.begin(),vp.end(),cmp);
    for (int i=0;i<cnt;i++){
        if (mst.size()==n-1) break;
        edge e = vp[i];
        if (Union(e.u,e.v)==true){
            mst.push_back(e);
            d+=e.w;
        }
    }
    if (mst.size() != n-1){
        cout<<"Do thi khong lien thong";
    }
    else {
        cout<<"dH = "<<d<<endl;
        for (auto x : mst){
            cout << x.u <<" "<< x.v << endl;
        }
    }
}

int main(){
    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            int x;
            cin >> x;
            if (x!=0 ) {
                cnt++;
                vp.push_back({i,j,x});
            }
        }
    }
    cnt--;
    make_set();
    kruskal();
}
