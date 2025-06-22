struct frac {
    ll num = 0, den = 1;
    signed sign = 1;
    frac() { }
    frac(ll n, ll d): num(n),den(d) { 
        if(num<0) num = -num, sign *= -1;
        if(den<0) den = -den, sign *= -1;
        simp();
        num *= sign;
    }
    frac(ll a) : num(a),den(1) { }
    void simp() {
         if(num==0) {
             den = 1;
             return;
         }
         ll g = gcd(num,den);
         if(!g) return;
         num /= g, den /= g;
    }
    //comp ops
    friend bool operator==(const frac a, const ll b) { return (a.den==1 && a.num == b); }
    friend bool operator==(const ll a, const frac b) { return b==a; }
    friend bool operator==(const frac a, const frac b) { return a.num==b.num && a.den==b.den; }
    friend bool operator!=(const frac a, const frac b) { return !(a==b); }
    //arithmetic ops
    friend frac operator*(const frac a, const frac b) { return frac(a.num*b.num,a.den*b.den); }
    friend frac operator/(const frac a, const frac b) { return frac(a.num*b.den,b.num*a.den); }
    friend frac operator+(const frac a, const frac b) { return frac(a.num*b.den+b.num*a.den,a.den*b.den); }
    friend frac operator-(const frac a, const frac b) { return a+frac(-b.num,b.den); }
    friend frac operator*(const frac a, const ll b) { return a*frac(b); }
    friend frac operator+(const frac a, const ll b) { return a+frac(b); }
    friend frac operator-(const frac a, const ll b) { return a+frac(-b); }
    friend frac operator*(const ll b, const frac a) { return a*b; }
    friend frac operator+(const ll b, const frac a) { return a+b; }
    friend frac operator-(const ll b, const frac a) { return frac(-a.num,a.den)+b; }
    //stream ops
    friend ostream& operator<<(ostream& out, const frac a) { return out << "(" << (long long)a.num << "/" << (long long)a.den << ")"; }
};
