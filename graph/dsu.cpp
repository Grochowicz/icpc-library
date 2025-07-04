struct dsu {
    vector<int> pa,sz;
    dsu(int n): pa(n),sz(n,1) {
        iota(all(pa),0);
    }

    int find(int a) {
        return pa[a] = (a==pa[a]?a:find(pa[a]));
    }

    void uni(int a, int b) {
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[b]>sz[a]) swap(a,b);
        pa[b] = a;
        sz[a]+=sz[b];
    }
};
