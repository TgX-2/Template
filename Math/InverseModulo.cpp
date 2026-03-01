// Fermat - m là số nguyên tố - O(log n)
int modinv(int a, int mod) {
	return poww(a, mod - 2, mod);
}

// Precompute 1 -> n - mod là số nguyên tố 
// inv[i] = mod - (mod / i) * inv[mod % i] % mod
const int maxn = 1e6 + 7;
int inv[maxn];

void precomupte(int n, int mod) {
	inv[1] = 1;
	for(int i = 2; i <= n; i++) 
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
}