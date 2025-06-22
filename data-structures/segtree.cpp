template<typename T>
struct segtree {
    const T neutral = 0;
    function<T(T,T)> comp = [&](T a, T b) {
        return a+b;
    };
    int n;
    vector<T> t;
    segtree(int n): n(n),t(2*n,neutral) { }
    segtree(vector<T> v) : n(v.size()),t(2*n,neutral) {
        for(int i=0;i<n;i++) at(i) = v[i];
        build();
    }

    void build() {
         for(int i=n-1; i>0; i--) t[i] = comp(t[i<<1],t[i<<1|1]);
    }

    void update(int p, T x) {
         for(t[p+=n] = x,p>>=1; p>0; p>>=1) t[p] = comp(t[p<<1],t[p<<1|1]);
    }

    T&at(int i) {
         return t[n+i];
    }

    T query(int l, int r) {
         T resl = neutral;
         T resr = neutral;
         for(l+=n, r+=n+1; l<r; l>>=1, r>>=1){
              if(l&1) resl = comp(resl,t[l++]);
              if(r&1) resr = comp(t[--r],resr);
         }
         return comp(resl,resr);
    }
};
