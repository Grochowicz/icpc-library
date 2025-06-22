template<typename T>
struct prefix {
    vector<T> pref;
    function<T(T,T)> comp = [&](T a, T b) {
        return a+b;
    };
    function<T(T,T)> inv = [&](T a, T b) {
        return a-b;
    };
    prefix(int n) : pref(n+1) { }
    prefix(vector<T> v) : pref(v.size()+1) {
        partial_sum(all(v), pref.begin()+1, comp);
    }
    T&at(int i) { return pref[i+1]; }
    void build() {
        partial_sum(all(pref), pref.begin(), comp);
    }
    T query(int l, int r) {
        return inv(pref[r+1],pref[l]);
    }
};
