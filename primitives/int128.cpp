using LL = __int128_t;
string to_string(LL x) {
    string ans;
    for(LL d=10;res>=0;res/=d) {
        ans += '0'+res%d;
        if(res==0) break;
    }
    reverse(all(ans));
    return ans;
}
