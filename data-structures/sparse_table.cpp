template<typename T>
struct sparse_table {
    const T neutral = 2e9;
    function<T(T,T)> comp = [&](T a, T b) {
        return min(a,b);
    };
    int n;
    vector<vector<T>> t;
    sparse_table(vector<T> v) : n(v.size()), t(__lg(n)+1, vector<T>(n,0)) {
        for(int i=0;i<n;i++) {
            t[0][i] = v[i];
        }
        for(int i=0;i<__lg(n);i++) {
            for(int j=0;j+(1<<i)<n;j++) {
                t[i+1][j] = comp(t[i][j],t[i][j+(1<<i)]);
            }
        }
    }

    T query(int l, int r) {
        if(l>r) return neutral;
        int x = __lg(r-l+1);
        return comp(t[x][l],t[x][r-(1<<x)+1]);
    }
};
