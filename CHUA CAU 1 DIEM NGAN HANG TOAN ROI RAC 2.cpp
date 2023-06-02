
//Câu 1.1
// dfs theo quay lui
void dfs(int u){
    unused[u] = 1;
    for (int x = 1; x <= n; x++){
        if (a[u][x] == 1 && unused[x] == 0) {
            dfs(x);
        }
    }
}
// dfs theo ngan xep
void dfs(int u){
    st.push(u);
    unused[u]=1;
    while (st.size()!=0){
        int s=st.top();
    	for (int x = 1; x <= n; x++){
        	if (a[i][x] == 1 && unused[x] == 0) {
                unused[x]=1;
                st.push(s);
                st.push(x);
                break;
            }
        }
    }
}
//Câu 1.2
void BFS(int u) {
    queue<int> q;
    q.push(u);
    unused[u] = 1;
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int x = 1; x <= n; x++) {
            if (a[s][x] == 1 && unused[x] == 0) {
                unused[x] = 1;
                q.push(x);
            }
        }
    }
}
//Câu 1.3
int TPLT_DFS(){
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (unused[i]==0){
            cnt++;
            bfs(i);
        }
    }
    return cnt;
}
//Câu 1.4
int TPLT_BFS(){
    int cnt=0;
    for (int i=1;i<=n;i++){
        if (unused[i]==0){
            cnt++;
            bfs(i);
        }
    }
    return cnt;
}
//Câu 1.5
void DFS(int u){
    unused[u]=1;
	for (int x = 1; x <= n; x++) {
         if (a[u][x] == 1 && unused[x] == 0) {
            int c=u;
            int c1=x;
            if (c>c1) swap(c,c1);
            T.push_back({c,c1});
            DFS(x);
        }
    }
}
void T_DFS(int u){
    for (int i=1;i<=n;i++) unused[i]=0;
    vector<pair<int,int>> T;
	DFS(u);
    if (T.size()<n-1){
        cout<<"Do thi khong lien thong";
    }
    else {
        for (auto x : T){
            cout << x.first << " " << x.second << endl;
        }
    }
}
//Câu 1.6
void T_BFS(int u){
    for (int i=1;i<=n;i++) unused[i]=0;
    queue<int> q;
    vector<pair<int,int>> T;
    q.push(u);
    unused[u]=1;
    while (q.size()!=0){
        int s = q.front();
        q.pop();
		for (int x = 1; x <= n; x++) {
            if (a[s][x] == 1 && unused[x] == 0) {
                unused[x]=1;
                T.push_back({s,x});
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
//Câu 1.7
void EULER(int u) {
    vector<int> ec;
    stack<int> st;
    st.push(u);
    while (!st.empty()) {
        int x = st.top();
        bool hasAdjacent = false;
        for (int y = 1; y <= n; y++) {
            if (a[x][y] == 1) {
                hasAdjacent = true;
                st.push(y);
                a[x][y] = 0;
                a[y][x] = 0;
                break;
            }
        }
        if (!hasAdjacent) {
            st.pop();
            ec.push_back(x);
        }
    }
    reverse(ec.begin(), ec.end());
    for (int x : ec) {
        cout << x << " ";
    }
}
//Câu 1.8
void DIJKSTRA(int s) {
    vector<int> d(n + 1, INF);
    vector<int> truoc(n + 1, s);
    vector<bool> T(n + 1, true);
    d[s] = 0;
    for (int v = 1; v <= n; v++) {
        if (v != s) {
            d[v] = a[s][v];
            truoc[v] = s;
        }
    }
    T[s] = false;
    while (true) {
        int u;
        int minDist = INF;
        for (int v = 1; v <= n; v++) {
            if (T[v] && d[v] < minDist) {
                minDist = d[v];
                u = v;
            }
        }
        if (minDist == INF) {
            break;  // Không còn d?nh trong T
        }
        T[u] = false;
        for (int v = 1; v <= n; v++) {
            if (T[v] && d[v] > d[u] + a[u][v]) {
                d[v] = d[u] + a[u][v];
                truoc[v] = u;
            }
        }
    }
}
//Câu 1.9
void FLOYD(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			d[i][j]=a[i][j];
			if (a[i][j]!=INF) nex[i][j]=j;
			else nex[i][j]=0;
		}
	}	
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (d[i][j]> d[i][k]+d[k][j]){
					d[i][j]= d[i][k]+ d[k][j];
					nex[i][j]=nex[i][k];
				}
			}
		}
	}
}
//Câu 1.10
struct canh{
	int x, y, w;
};
void PRIM(int u){
	vector<canh> MST; // cay khung
	int distance = 0; // chieu dai cay khung
	used[u] = true; // dua dinh u vao tap V(MST)
	while(MST.size() < n - 1){
		//e = (x, y) : C?nh ng?n nh?t có x thu?c V và y thu?c V(MST)
		int min_w = INT_MAX;
		int X, Y; // luu 2 dinh cua canh e
		for(int i = 1; i <= n; i++){
			//neu dinh i thuoc tap V(MST)
			if(used[i]){
				//duyet danh sach ke cua dinh i
				for (int j = 1;j <= n; j++){
					if(!used[j] && d[i][j] < min_w){
						min_w = trongso;
						X = j; Y = i;
					}
				}
			}
		}
		MST.push_back({X, Y, min_w});
		distance += min_w;
		used[X] = true; // cho dinh X vao V(MST), loai X khoi tap V
	}
	cout << distance << endl;
	for(canh e : MST){
		cout << e.x <<  " " << e.y << " " << e.w << endl;
	}
}
//Câu 1.11
void HALMITON(int k){
	for (int i = 1;i <= n ; i++){
		if (a[i][x[k-1]]==1){
	        if (k == n+1 && y == s){
	            for (int i=1;i<=n;i++) cout<<x[i]<<" ";
	            cout<<s;
	            cout<<endl;
	        }
	        else if (unused[y]==0){
	            unused[y]=1;
	            x[k]=y;
	            hmt(k+1);
	            unused[y]=0;
	        }
	    }
    }
}
void hmtCircle(int v){
    for (int i=1;i<=n;i++) unused[i]=0;
    x[1]=v;
    unused[v]=1;
    hmt(2);
}

















