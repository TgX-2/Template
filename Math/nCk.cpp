// C(n, k) = n! / (k! * (n - k)!)
// C(n, k) = fact[n] * invfact[k] % mod * invfact[n - k] % mod

// Precompute O(n) - get nCk O(1)
// mod là số nguyên tố

const int maxn = 1e6 + 7;
int fact[maxn], invfact[maxn];

void precompute() {
	fact[0] = 1;
	for(int i = 1; i <= n; i++) 
		fact[i] = (fact[i - 1] * i) % mod;

	invfact[n] = poww(fact[n], mod - 2, mod);
	for(int i = n; i >= 1; i--)
		invfact[i - 1] = (invfact[i] * i) % mod;
}

int nCk(int n, int k) {
	return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}


