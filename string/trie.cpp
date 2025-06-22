struct trie {
    vector<map<char,int>> t;
    vector<int> value;
    trie() : t(1),value(1) {}

    void insert(string s, int v=1){
        int id = 0;
        for (char c:s) {
            if(!t[id].count(c)) {
                t[id][c] = t.size();
                t.emplace_back();
                value.emplace_back(0);
            }
            id = t[id][c];
        }
        value[id] = v;
    }

    void erase(string s) {
        if(!count(s)) return;

        vector<int> path(1,0);
        int id = 0;
        for(char c:s) {
            id = t[id][c];
            path.emplace_back(id);
        }
        value[id] = 0;
        for(int i=path.size()-1;i>0;i--) {
            if(value[path[i]]) break;
            t[path[i-1]].erase(s[i-1]);
        }
    }

    int get_value(string s) {
        int id = 0, res = 0;
        for (char c:s){
            if(!t[id].count(c)) return -1;
            id = t[id][c];
        }
        res = value[id];
        return res;
    }

    int dfs(int id, int i, string&s, int error=0) {
        if(error<0) return 0;
        if(t[id].empty()) {
            return error>=s.size()-i;
        }
        if(i>=s.size()) {
            int q = !!value[id];
            for(auto [k,v]:t[id]) {
                q += dfs(v,i+1,s,error-1);
            }
            return q;
        }

        int q = 0;
        for(auto [k,v]:t[id]) {
            q += dfs(v,i+1,s,error-(k!=s[i]));
        }
        return q;
    }

    int count(string s, int error=0) {
        return dfs(0,0,s,error);
    }
};
