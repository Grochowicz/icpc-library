const ll inf = 1e15;
// O(m^2 ln m ln F)
struct ford_fulkerson {
    struct edge {
        int to,rev;
        ll flow,cap;
        bool res,vis;
        edge(int to, int rev, int cap, bool res) : to(to),rev(rev),flow(0),cap(cap),res(res),vis(false) { }

        bool operator<(const edge&o) const { return (cap-flow) < (o.cap-o.flow); }
    };
    int n;
    vector<vector<edge>> adj;
    vector<pair<int,int>> p;
    ford_fulkerson(int n) : n(n),adj(n),p(n) { }

    void add(int a, int b, int c) {
        adj[a].emplace_back(b,adj[b].size(),c,false);
        adj[b].emplace_back(a,adj[a].size()-1,0,true);
    }

    ll prim(int s, int t) {
        p[t] = make_pair(-1,-1);
        p[s] = make_pair(s,0);
        priority_queue<pair<edge,int>> q;
        for(auto&e:adj[s]) q.emplace(e,s);
        set<int> has;
        has.emplace(s);
        while(not q.empty() and has.size()<n) {
            auto[e,u] = q.top(); q.pop();
            if(not has.count(e.to)) {
                has.emplace(e.to);
                p[e.to] = make_pair(u, adj[e.to][e.rev].rev);
            }
            if(e.to==t) break;
            for(auto ev:adj[e.to]) if(not has.count(ev.to)) q.emplace(ev,e.to);
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
            ff = prim(s,t);
            if(not ff) break;
            F += ff;
        }
        return F;
    }
};
