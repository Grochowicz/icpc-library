template<int dig=62>
struct xor_trie {
    vector<array<int,2>> t;
    int id = 1;

    xor_trie(int n) : t(dig*n,{0,0}) { }

    void insert(ll u) {
        int cur = 0;
        for(int i=dig-1;i>=0;i--) {
            int&nxt = t[cur][u>>i&1];
            if(nxt==0) {
                nxt = id++;
            }
            cur = nxt;
        }
    }

    ll max_xor(ll u) {
        int cur = 0;
        ll big = 0;
        for(int i=dig-1;i>=0;i--) {
            int o = t[cur][u>>i&1^1];
            int z = t[cur][u>>i&1];
            int nxt = z;
            if(o) {
                nxt = o;
                big ^= (1ll<<i);
            }
            cur = nxt;
        }
        return big;
    }
};
