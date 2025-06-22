struct hsh {
    int n = 6;
    vector<ll> mods = {(1ll<<19)-1,(1ll<<31)-1,int(1e9)+7,int(1e9)+9,567629137,998244353};

    vector<ll> val;
    vector<hsh> pow;
    vector<hsh> pref;

    hsh(int x=0) : val(n,x) { 
        for(int i=0;i<n;i++) {
            val[i] %= mods[i];
        }
    }
    hsh(string s) : val(n,0) { build(s); }

    void build(string s) {
        hsh p(1);
        hsh res(0);

        pow.emplace_back(p);
        pref.emplace_back(res);

        for(char c:s) {
            int cc = c-'a'+1;
            res = res + (p*cc);
            p = p * 31;

            pow.emplace_back(p);
            pref.emplace_back(res);
        }
        val = res.val;
    }

    hsh query(int l, int r) {
        return (pref[r+1] - pref[l]) / pow[l];
    }

    bool operator==(hsh o) {
        bool ok = 1;
        for(int i=0;i<n;i++) {
            ok &= val[i]==o.val[i];
        }
        return ok;
    }

    bool operator<(hsh o) const {
        for(int i=0;i<n;i++) {
            if(val[i]!=o.val[i]) return val[i]<o.val[i];
        }
        return 0;
    }

    hsh operator+(hsh o) {
        hsh res(n);
        for(int i=0;i<n;i++) {
            res.val[i] = val[i]+o.val[i];
            if(res.val[i]>=mods[i]) res.val[i] -= mods[i];
        }
        return res;
    }

    hsh operator-(hsh o) {
        hsh res(n);
        for(int i=0;i<n;i++) {
            res.val[i] = val[i]-o.val[i];
            if(res.val[i]<0) res.val[i] += mods[i];
        }
        return res;
    }

    hsh operator*(ll b) {
        hsh res(n);
        for(int i=0;i<n;i++) {
            res.val[i] = (val[i]*b) % mods[i];
        }
        return res;
    }

    ll bx(ll b, ll e, ll mod) {
        ll res = 1;
        for(;e;e>>=1) {
            if(e&1) res = res*b % mod;
            b = b*b % mod;
        }
        return res;
    }

    hsh operator/(hsh o) {
        hsh res(n);
        for(int i=0;i<n;i++) {
            res.val[i] = (val[i] * bx(o.val[i],mods[i]-2,mods[i])) % mods[i];
        }
        return res;
    }

    hsh operator/(ll b) {
        hsh res(n);
        for(int i=0;i<n;i++) {
            res.val[i] = (val[i] * bx(b,mods[i]-2,mods[i])) % mods[i];
        }
        return res;
    }

    string to_string() {
        string res = "<";
        for(int i=0;i<n;i++) {
            res += std::to_string(val[i]);
            if(i<n-1) res += ", ";
            else res += ">";
        }
        return res;
    }
    friend ostream& operator<<(ostream& out,hsh a) {
        return out << a.to_string();
    }
};
