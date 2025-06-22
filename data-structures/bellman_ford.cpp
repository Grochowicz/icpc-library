const ll inf = 1e18;
auto bellman_ford = [&](int st=0) {
    vector d(n, inf);
    d[st] = 0;
    for(int i=0;i<n;i++) {
        for(auto[a,b,c]:edges) {
            if(d[a]!=inf) {
                ll at = d[a]+c;
                if(at<d[b]) d[b] = at;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(auto[a,b,c]:edges) {
            if(d[a]!=inf) {
                ll at = d[a]+c;
                if(at<d[b]) d[b] = -inf;
            }
        }
    }
    return d;
};
