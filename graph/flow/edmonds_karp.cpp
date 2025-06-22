const ll inf = 1e15;
// O(n m^2)
// ford fulkerson com bfs
struct edmonds_karp {
    struct edge {
        int to,rev;
        ll flow,cap;
        bool res,vis;
        edge(int to, int rev, int cap, bool res) : to(to),rev(rev),flow(0),cap(cap),res(res),vis(false) { }
    };

    int n;
    vector<vector<edge>> adj;
    vector<pair<int,int>> p;
    edmonds_karp(int n) : n(n),adj(n),p(n) { }

    void add(int a, int b, int c) {
        adj[a].emplace_back(b,adj[b].size(),c,false);
        adj[b].emplace_back(a,adj[a].size()-1,0,true);
    }

    ll bfs(int s, int t) {
        for(auto&u:p) u = make_pair(-1,-1);
        p[s] = make_pair(s,0);
        queue<int> q;
        q.emplace(s);

        while(not q.empty()) {
            auto u = q.front(); q.pop();
            for(int i=0;i<adj[u].size();i++) {
                auto e = adj[u][i];
                if(p[e.to].first==-1 and e.cap-e.flow>0) {
                    q.emplace(e.to);
                    p[e.to] = make_pair(u, i);
                    if(e.to==t) break;
                }
            }
        }

        if(p[t].first==-1) return 0;
        int x = t;
        ll ff = inf;
        while(p[x].first!=x) {
            auto[prev,idx] = p[x];
            auto&e = adj[prev][idx];
            ff = min(ff,e.cap-e.flow);
            x = prev;
        }
        x = t;
        while(p[x].first!=x) {
            auto[prev,idx] = p[x];
            auto&e = adj[prev][idx];
            e.flow += ff;
            adj[e.to][e.rev].flow -= ff;
            x = prev;
        }
        return ff;
    }

    ll F = 0;
    ll max_flow(int s, int t) {
        ll ff;
        while(1) {
            ff = bfs(s,t);
            if(not ff) break;
            F += ff;
        }

        return F;
    }
};
