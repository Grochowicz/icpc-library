int d[maxn], mu[maxn], phi[maxn];
vector<int> primes;
void sieve() {
    for(int i=1;i<maxn;i++) phi[i]=i, mu[i]=1;

    for(int i=2;i<maxn;i++) {
        if(!d[i]) {
            primes.push_back(i);
            for(int j=i;j<maxn;j+=i) {
                if(j>i) d[j]++;
                if(j%(i*i)==0) mu[j] = 0;
                mu[j] *= -1;

                phi[j] -= phi[j]/i;
            }
        }
    }
}
