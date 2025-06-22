struct xor_trie {
    int dig;
    map<int,int> m;
    vector<int> t;
    int id;

    xor_trie(int dig) : dig(dig), id(0) { }

    void insert(int a) {
        int at = 1;
        for(int b = dig-1;b>=0;b--) {
            at <<= 1;
            at += a>>b&1;
            m[at] = id++;
            t.emplace_back(1);
        }
    }

    int max_xor(int a) {
        int at = 1;
        int big = a;
        for(int b = dig-1;b>=0;b--) {
            at <<= 1;
            at += (a>>b&1)^1;
            if(!m.count(at) or !t[m[at]]) at ^= 1;
            if(!m.count(at) or !t[m[at]]) break;

            big ^= (at&1)<<b;
        }
        return big;
    }
};
