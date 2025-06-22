#define comp(a,b) ((a)+(b))
template<typename T>
struct segtree2D {
    const T neutral(0);
    int n,m;
    vector<vector<T>> t;

    segtree2D(int n, int m): n(n), m(m), t(2*n, vector<T>(2*m,neutral)) { }
    T& at(int i,int j) { return t[n+i][m+j]; }

    void build() {
        for(int i=2*n-1;i>=n;i--) {
            for(int j=m-1;j>0;j--) {
                t[i][j] = comp(t[i][j<<1],t[i][j<<1|1]);
            }
        }
        for(int i=n-1;i>0;i--) {
            for(int j=2*m-1;j>0;j--) {
                t[i][j] = comp(t[i<<1][j],t[i<<1|1][j]);
            }
        }
    }

    T inner_query(int idx, int l, int r) {
        T res = neutral;
        auto&c = t[idx];
        for(l+=m,r+=m+1;l<r;l>>=1,r>>=1) {
            if(l&1) res = comp(res,c[l++]);
            if(r&1) res = comp(res,c[--r]);
        }
        return res;
    }
    T query(int a, int b, int c, int d) {
        T res(neutral);
        for(a+=n,c+=n+1;a<c;a>>=1,c>>=1) {
            T tr(neutral);
            if(a&1) tr = comp(tr,inner_query(a++,b,d));
            if(c&1) tr = comp(tr,inner_query(--c,b,d));
            res = comp(res,tr);
        }
        return res;
    }

    void inner_update(int idx, int i, T x) {
        auto&c = t[idx];
        for(c[i+=m]=x,i>>=1;i;i>>=1) {
            c[i] = comp(c[i<<1],c[i<<1|1]);
        }
    }
    void update(int i, int j, T x) {
        inner_update(i+=n,j,x);
        for(i>>=1;i;i>>=1) {
            T val = comp(t[i<<1][j+m],t[i<<1|1][j+m]);
            inner_update(i,j,val);
        }
    }
};
