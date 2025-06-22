struct suffix_automaton {
    vector<int> len, link, cnt;
    vector<vector<int>> adj;
    vector<vector<int>> to;
    int last,id;
#define ALPHA 26
 
    suffix_automaton(string&s) {
        last = 1, id = 1;
        len.assign(2,0);
        link.assign(2,0);
        to.assign(2,vector(ALPHA,0));
        for(char c:s) insert(c);
    }
 
    int make_node() {
        id++;
        len.emplace_back();
        link.emplace_back();
        to.emplace_back(ALPHA,0);
        return id;
    }
 
    void insert(char cc) {
        int c = cc-'a';
        int cur = make_node();
        len[cur] = len[last]+1;
        int p = last;
        while(not to[p][c]) {
            to[p][c] = cur;
            p = link[p];
        }
        if(not p) {
            link[cur] = 1;
        }
        else {
            int q = to[p][c];
            if(len[q]==len[p]+1) {
                link[cur] = q;
            }
            else {
                int clone = make_node();
                to[clone] = to[q];
                link[clone] = link[q];
                len[clone] = len[p]+1;
                for(;to[p][c]==q;p=link[p]) to[p][c] = clone;
                link[q] = link[cur] = clone;
            }
        }
        last = cur;
    }
 
    void build_tree() {
        adj.assign(id+1,vector<int>());
        for(int i=1;i<=id;i++) {
            adj[link[i]].push_back(i);
        }
    }
 
    int dfs_cnt(int u) {
        for(int v:adj[u]) {
            cnt[u] += dfs_cnt(v);
        }
        return cnt[u];
    }
 
    int occurrences(string s) {
        int p = 1;
        for(char cc:s) {
            int c = cc-'a';
            if(to[p][c]) {
                p = to[p][c];
            }
        }
        build_tree();
        cnt.assign(id+1,1);
        return dfs_cnt(p);
    }
 
    ll distinct_substrings() {
        vector<ll> dp(id+1,-1);
        return dfs_dsub(1,dp)-1;
    }
 
    ll dfs_dsub(int u,vector<ll>&dp) {
        ll res = 1;
        if(dp[u]!=-1) return dp[u];
        for(int i=0;i<ALPHA;i++) {
            int v = to[u][i];
            if(not v) continue;
            res += dfs_dsub(v,dp);
        }
        return dp[u] = res;
    }
 
};
