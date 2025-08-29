const int maxlog = 63;

ll base[maxlog], rank;

void insertVector(ll mask) {
     ll f = __builtin_ctzll(mask&-mask);
     for(int i=f;i<maxlog;i++) {
          if(!(mask&(1LL<<i))) continue;
          if(!base[i]) {
              base[i] = mask;
              rank++;
              return;
          }

          mask ^= base[i];
     }
}
