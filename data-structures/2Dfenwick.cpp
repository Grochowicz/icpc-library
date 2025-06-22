template<typename T>
struct fenwick2D {
    const T neutral(0);
    int n,m;
    vector<vector<T>> t;
    fenwick2D(int n, int m): n(n+1),m(m+1),t(n+1,vector<T>(m+1,neutral)) { }

    void update(int ii, int jj, T x) {
        for(int i=++ii;i<n;i+=(i&-i)) {
            for(int j=++jj;j<m;j+=(j&-j)) {
                t[i][j] += x;
            }
        }
    }

    T query(int ii, int jj) {
        T ret(neutral);
        for(int i=++ii;i;i-=(i&-i)) {
            for(int j=++jj;j;j-=(j&-j)) {
                ret += t[i][j];
            }
        }
        return ret;
    }

    T query(int a, int b, int c, int d) {
        return query(c,d)-query(c,b-1)-query(a-1,d)+query(a-1,b-1);
    }
};
