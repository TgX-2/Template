// Code O(sqrt(n))
int Phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while(n % i == 0) n /= i;
            ans -= ans / i;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

// Code precompute O(n log log n) 
const int maxn = 1e6 + 7;
int phi[maxn];

void sieve() {
	for(int i = 1; i <= n; i++) phi[i] = i;

	for(int i = 2; i <= n; i++) if (phi[i] == i)
		for(int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
}