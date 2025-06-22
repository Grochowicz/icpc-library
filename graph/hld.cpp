template<class T>
struct HLD {
    int n;
    vector<ll> val;
    vector<int> p, sz,tour,idx,head;
    int szt = 0;
    T ds;

    HLD(int n) : n(n),val(n,ds.neutral),p(n),sz(n),tour(n),idx(n),head(n),ds(n) { }
    HLD(vector<ll> v) : n(v.size()),val(v),p(n),sz(n),tour(n),idx(n),head(n),ds(n) { build(); }

    void build(int root = 0) {

    void build(int root = 0) {
        p[root] = root;
        head[root] = root;
        dfs_sz(root);
        dfs_tour(root);
        for(int i=0;i<n;i++) {
            ds.at(idx[i]) = val[i];
        }
        ds.build();
    }

    void dfs_sz(int u) {
        sz[u] = 1;
        for(int&v:adj[u]) if(v!=p[u]) {
            p[v] = u;
            dfs_sz(v);
            sz[u] += sz[v];
            if(sz[v]>sz[adj[u][0]] or adj[u][0]==p[u]) swap(v,adj[u][0]);
        }
    }

    void dfs_tour(int u) {
        tour[szt] = u;
        idx[u] = szt;
        szt++;
        for(int v:adj[u]) if(v!=p[u]) {
            head[v] = (v==adj[u][0] ? head[u] : v);
            dfs_tour(v);
        }
    }

    int lca(int u, int v) {
        if(idx[u]>idx[v]) swap(u,v);
        while(head[u]!=head[v]) {
            v = p[head[v]];
            if(idx[u]>idx[v]) swap(u,v);
        }
        return u;
    }

    int get_kth(int u, int k) {
        if(!k or !u) return u;
        int dif = idx[u] - idx[head[u]];
        if(dif>=k) return tour[idx[u]-k];

        return get_kth(p[head[u]],k-dif-1);
    }

    void update_point(int u, ll x) {
        ds.update(idx[u],x);
    }

    void update_subtree(int u, ll x) {
        ds.update(idx[u],idx[u]+sz[u]-1);
    }

    void update_path(int u, int v, ll x) {
        if(idx[u]>idx[v]) swap(u,v);

        while(head[u]!=head[v]) {
            ds.update(idx[head[v]],idx[v],x);
            v = p[head[v]];
            if(idx[u]>idx[v]) swap(u,v);
        }
        ds.update(idx[u],idx[v],x);
    }

    ll query_point(int u) {
        return ds.query(idx[u]);
    }

    ll query_subtree(int u) {
        return ds.query(idx[u],idx[u]+sz[u]-1);
    }

    ll query_path(int u, int v) {
        if(idx[u]>idx[v]) swap(u,v);

        ll ret = 0;
        while(head[u]!=head[v]) {
            ret = ds.comp(ret,ds.query(idx[head[v]],idx[v]));
            v = p[head[v]];
            if(idx[u]>idx[v]) swap(u,v);
        }
        ret = ds.comp(ret,ds.query(idx[u],idx[v]));
        return ret;
    }
};
