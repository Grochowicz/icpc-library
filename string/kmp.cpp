namespace KMP {
    vector<int> get_pi(string s) {
        int n = s.size();
        vector<int> pi(n);
        for(int i=1,j=0;i<n;i++) {
            while(j and s[i]!=s[j]) j = pi[j-1];
            if(s[i]==s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    vector<array<int,26>> automaton(string s) {
        int n = s.size();
        vector pi = get_pi(s);
        vector to(n+1,array<int,26>());
        to[0][s[0]-'a'] = 1;
        for(int i=1;i<n;i++) {
            for(int j=0;j<26;j++) {
                if(s[i]==(j+'a')) {
                    to[i][j] = i+1;
                }
                else to[i][j] = to[pi[i-1]][j];
            }
        }
        return to;
    }
};
