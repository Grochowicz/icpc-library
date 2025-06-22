int gin[maxn];
vector<int> revadj[maxn];
struct kosaraju {
    int n;
    vector<int> vis, rep;
    kosaraju(int n) : n(n),vis(n),rep(n) {
        for(int u=0;u<n;u++) {
            for(int v:adj[u]) {
                gin[v]++;
                revadj[v].push_back(u);
            }
        }
    }

    vector<int> order;
    void dfs(int u) {
        vis[u]++;
        for(int v:adj[u]) {
            if(!vis[v]) dfs(v);
        }
        order.push_back(u);
    }

    void revdfs(int u) {
        vis[u]++;
        for(int v:revadj[u]) {
            if(!vis[v]) {
                rep[v] = rep[u];
                revdfs(v);
            }
        }
    }

    void scc() {
        for(int u=0;u<n;u++) {
            if(!gin[u]) dfs(u);
        }
        for(int u=0;u<n;u++) {
            if(!vis[u]) dfs(u);
        }

        reverse(all(order));

        vis.assign(n,0);

        for(int i=0;i<n;i++) {
            int u = order[i];
            if(!vis[u]) {
                rep[u] = u;
                revdfs(u);
            }
        }
    }
};
