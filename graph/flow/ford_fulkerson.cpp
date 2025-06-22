const ll inf = 1e15;
// O(m F)
// ford fulkerson com dfs
struct ford_fulkerson {
    struct edge {
        int to,rev;
        ll flow,cap;
        bool res,vis;
        edge(int to, int rev, int cap, bool res) : to(to),rev(rev),flow(0),cap(cap),res(res),vis(false) { }
    };
    int n;
    vector<vector<edge>> adj;
    vector<pair<int,int>> p;
    ford_fulkerson(int n) : n(n),adj(n),p(n) { }

    void add(int a, int b, int c) {
        adj[a].emplace_back(b,adj[b].size(),c,false);
        adj[b].emplace_back(a,adj[a].size()-1,0,true);
    }

    ll dfs(int u, int t, ll flow=inf) {
        if(u==t) return flow;
        for(int i=0;i<adj[u].size();i++) {
            auto&e = adj[u][i];
            if(e.cap-e.flow == 0 or e.vis) continue;
            e.vis = true;
            ll f = dfs(e.to,t, min(flow,e.cap-e.flow));
            e.vis = false;
            if(not f) continue;
            e.flow += f;
            adj[e.to][e.rev].flow -= f;
            return f;
        }
        return 0;
    }

    ll F = 0;
    ll max_flow(int s, int t) {
        ll ff;
        while(1) {
            ff = dfs(s,t);
            if(not ff) break;
            F += ff;
        }
        return F;
    }
};
