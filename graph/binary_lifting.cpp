int kp[maxn][maxlg];

void dfs_bl(int u, int d=0) {
    if(d>1) for(int i=1;i<=__lg(d);i++) {
        kp[u][i] = kp[kp[u][i-1]][i-1];
    }

    for(int v:adj[u]) {
        kp[v][0] = u;
        dfs_bl(v, d+1);
    }
}

int msb(int x) {
    while(x!=(x&-x)) {
        x -= x&-x;
    }
    return x;
}

int get_kth(int u, int k) {
    if(u==-1) return -2;
    if(k==0) return u;
    int ctz = __builtin_ctz(msb(k));
    return get_kth(kp[u][ctz],k-msb(k));
}
