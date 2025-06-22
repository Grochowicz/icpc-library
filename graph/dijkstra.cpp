const ll inf = 1e18;
auto dijkstra = [&](int st=0) {
    vector d(n, inf);
    using T = pair<ll,int>;
    priority_queue<T,vector<T>,greater<T>> q;
    d[st] = 0;
    q.emplace(0,st);

    while(!q.empty()) {
        auto[at,u] = q.top(); q.pop();
        if(at>d[u]) continue;

        for(auto[v,w]:adj[u]) {
            if(d[u]+w < d[v]) {
                d[v] = d[u]+w;
                q.emplace(d[v],v);
            }
        }
    }

    return d;
};
