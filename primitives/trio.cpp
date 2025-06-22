template<typename T, typename U, typename V>
struct trio {
    T first; U second; V third;
    void tie(T&a,U&b,V&c) { a=first,b=second,c=third; }
    trio(T a,U b,V c) : first(a),second(b),third(c) { }
    bool operator<(trio o) {
        if(first!=o.first) return first<o.first;
        else if(second!=o.second) return second<o.second;
        else return third<o.third;
    }
};
