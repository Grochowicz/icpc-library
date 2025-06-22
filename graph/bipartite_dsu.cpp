struct bipartite_dsu {
    vector<pair<int,int>> pa;
    vector<int> sz, bip;
    bipartite_dsu(int n) : sz(n,1), bip(n,1) {
        iota(all(pa),0);
    }

    pair<int,int> find(int a) {
        if(a==pa[a].first) return pa[a];

        int imp = pa[a].second;
        auto f = find(pa[a].first);
        f.second ^= imp;
        return pa[a] = f;
    }

    void uni(int a, int b, int w=1) {
        int x, y;
        tie(a,x) = find(a);
        tie(b,y) = find(b);
        if(a==b) {
            if(x^y^w) bip[a] = 0;
            return;
        }
        if(sz[b]>sz[a]) swap(a,b);
        pa[b] = make_pair(a,x^y^w);
        bip[a] &= bip[b];
        sz[a]+=sz[b];
    }

    bool is_bip(int a) {
        return bip[find(a).first];
    }
};
