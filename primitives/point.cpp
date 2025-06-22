template<typename T>
struct point {
    T x, y;
    point() : x(0), y(0) {}
    point(T x, T y) : x(x), y(y) {}
    ll dist2(const point &p) {
        ll dx = x - p.x;
        ll dy = y - p.y;
        return dx * dx + dy * dy;
    }
    //vector ops
    point operator*(const T &b) { return point(x * b, y * b); }
    point operator/(const T &b) { return point(x / b, y / b); }
    point operator-(const point &b) { return point(x - b.x, y - b.y); }
    point operator+(const point &b) { return point(x + b.x, y + b.y); }
    ll operator*(const point &b) { return x * b.x + y * b.y; }
    ll operator^(const point &b) { return x * b.y - y * b.x; }
    //stream ops
    friend istream &operator>>(istream &in, point &a) { return in >> a.x >> a.y; }
    friend ostream &operator<<(ostream &out, const point &a) { return out << "(" << a.x << "," << a.y << ")"; }
    //comp ops
    bool operator< (const point&b) const { if(x!=b.x) return x<b.x; else return y<b.y;}
    bool operator==(const point&b) const { return x==b.x && y==b.y; }
    bool operator<=(const point&b) const { return *this < b || *this==b; }
    bool operator> (const point&b) const { return !(*this < b); }
    bool operator>=(const point&b) const { return *this > b || *this==b; }
    bool operator!=(const point&b) const { return !(this==b); }
};
