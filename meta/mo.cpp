struct query {
    int i, l, r, res;
    query(int i=0, int l=0, int r=0) : i(i), l(l), r(r) { assert(l<=r); }
};

const int maxn = 2e5+5;
int freq[maxn];

void mo(vector<int>&v, vector<query>&qq) {
    ll n = v.size(), q = qq.size();
    const int blk = (int)ceil(sqrt((n*n+q-1)/q));
    debug(n,q,blk);

    auto mo_comp = [&](query a, query b) -> bool {
        if(a.l/blk != b.l/blk) return a.l<b.l;
        else return ((a.l/blk)&1)^(a.r < b.r);
    };
    sort(all(qq), mo_comp);

    int l = -1, r = -1;
    int cur = 0;
    for(auto&u:qq) {
        while(r<u.r) {
            r++;
            if(freq[v[r]]==0) cur++;
            freq[v[r]]++;
        }
        while(l>u.l) {
            l--;
            if(freq[v[l]]==0) cur++;
            freq[v[l]]++;
        }
        while(r>u.r) {
            freq[v[r]]--;
            if(freq[v[r]]==0) cur--;
            r--;
        }
        while(l<u.l) {
            if(l>=0) {
                freq[v[l]]--;
                if(freq[v[l]]==0) cur--;
            }
            l++;
        }

        u.res = cur;
    }

    auto ret_comp = [&](query a, query b) {
        return a.i < b.i;
    };
    sort(all(qq), ret_comp);
}
