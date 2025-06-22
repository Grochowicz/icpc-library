template<typename T>
struct fenwick {
    const T neutral = 0;
    function<T(T,T)> comp = [&](T a, T b) {
        return a+b;
    };
    function<T(T,T)> inv = [&](T a, T b) {
        return a-b;
    };
    int n;
    vector<T> t;
    fenwick(int n): n(n+1),t(n+1,neutral) { }

    T&at(int i) {
        return t[i+1];
    }

    void build() {
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) t[j] += t[i];
        }
    }

    void update(int ii, T x) {
        for(int i=++ii;i<n;i+=(i&-i)) {
            t[i] = comp(t[i],x);
        }
    }

    T query(int ii) {
        T ret(neutral);
        for(int i=++ii;i;i-=(i&-i)) {
            ret = comp(ret,t[i]);
        }
        return ret;
    }

    T query(int l, int r) {
        return inv(query(r),query(l-1));
    }
};
