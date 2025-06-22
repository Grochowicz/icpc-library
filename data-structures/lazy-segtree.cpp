template<typename T>
struct segtree {
    const T neutral = 0;
    function<T(T,T)> comp = [&](T a, T b) {
        return a+b;
    };

    vector<T> v, t, lazy;
    vector<bool> replace;
    int n;
    segtree(int n) : n(n) {
        v.assign(n,neutral);
        t.assign(4*n,neutral);
        lazy.assign(4*n,neutral);
        replace.assign(4*n,neutral);
    }

    void build() { build(1,0,n-1); }
    void build(int p, int l, int r) {
        if(l==r) {
            t[p] = v[l];
            return;
        }
        int mid = l+(r-l)/2;
        build(p<<1,l,mid);
        build(p<<1|1,mid+1,r);
        t[p] = t[p<<1]+t[p<<1|1];
    }

    void push(int p, int l, int r) {
        if(replace[p]) {
            t[p] = lazy[p]*(r-l+1);
            if(l<r) {
                replace[p<<1] = replace[p<<1|1] = replace[p];
                lazy[p<<1] = lazy[p<<1|1] = lazy[p];
            }
        }
        else if(lazy[p]) {
            t[p] += lazy[p]*(r-l+1);
            if(l<r) {
                lazy[p<<1] += lazy[p];
                lazy[p<<1|1] += lazy[p];
            }
        }
        replace[p] = 0;
        lazy[p] = 0;
    }

    T query(int L, int R) { return query(L,R,1,0,n-1); }
    T query(int L, int R, int p, int l, int r) {
        push(p,l,r);
        if(l>R or r<L) return 0;
        if(L <= l and r <= R) return t[p];
        int mid = l+(r-l)/2;
        T a = query(L,R,p<<1,l,mid);
        T b = query(L,R,p<<1|1,mid+1,r);
        return a+b;
    }

    void update(int L, int R, T x, bool repl) { update(L,R,x,repl,1,0,n-1); }
    void update(int L, int R, T x, bool repl, int p, int l, int r) {
        push(p,l,r);
        if(l>R or r<L) return;
        if(L <= l and r <= R) {
            lazy[p] = x;
            replace[p] = repl;
            push(p,l,r);
            return;
        }
        int mid = l+(r-l)/2;
        update(L,R,x,repl,p<<1,l,mid);
        update(L,R,x,repl,p<<1|1,mid+1,r);
        t[p] = t[p<<1]+t[p<<1|1];
    }
};
