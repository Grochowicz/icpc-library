vector<int> toposort;
vector<int> deg(n);
[&]() {
    for(int u=0;u<n;u++) {
        for(int v:adj[u]) {
            deg[v]++;
        }
    }
    vector<int> d = deg;
    vector<int> zero;
    for(int i=0;i<n;i++) {
        if(!d[i]) zero.push_back(i);
    }
    while(!zero.empty()) {
        int t = zero.back(); zero.pop_back();
        toposort.push_back(t);
        for(int v:adj[t]) {
            d[v]--;
            if(!d[v]) zero.push_back(v);
        }
    }
}();
