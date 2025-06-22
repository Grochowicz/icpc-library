// crivo que computa quantidade de divisores, função de mobius e totiente em O(n log n)
int d[N], mu[N], phi[N];
vector<int> primes;
void sieve() {
    for(int i=1;i<N;i++) phi[i]=i, mu[i]=1;

    for(int i=2;i<N;i++) {
        if(!d[i]) {
            primes.push_back(i);
            for(int j=i;j<N;j+=i) {
                if(j>i) d[j]++;
                if(j%(i*i)==0) mu[j] = 0;
                mu[j] *= -1;

                phi[j] -= phi[j]/i;
            }
        }
    }
}
