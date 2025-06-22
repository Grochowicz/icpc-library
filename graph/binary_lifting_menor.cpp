int kp[LG][N];
int res[LG][N];
int v[N];

void build(int n) {
    vector<int> gt(1,n);
    for(int i=n-1;i>=0;i--) {
        while(v[gt.back()] <= v[i]) gt.pop_back();
        kp[0][i] = gt.back();
        res[0][i] = 1;
        gt.emplace_back(i);
    }
    kp[0][n] = n;
    for(int i=1;i<LG;i++) {
        for(int j=0;j<=n;j++) {
            kp[i][j] = kp[i-1][kp[i-1][j]];
            res[i][j] = res[i-1][j] + res[i-1][kp[i-1][j]];
        }
    }
}
//quantos elementos sao o primeiro maior se eu começar em l e ir até r
ll query(int l, int r) {
    if(l>r) return 0;
    //primeiro maior à direita
    ll ans = 0;
    int x = l;
    for(int b=LG-1;b>=0;b--) {
        if(kp[b][x] <= r) {
            ans += res[b][x];
            x = kp[b][x];
        }
    }
    return ans;
}
