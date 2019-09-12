#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull; 

ull N, K, ans;
ull cache[1005][1005];

ull dp (ull N, ull K);

int main() {
	// freopen("poem.in", "r", stdin);
	// freopen("poem.out","w",stdout);

	scanf("%llu %llu", &N, &K);

	for (ull i=1; i<=K; i++) {
		ans += dp(N, i);
	}

	printf("%llu\n", ans);
}

ull dp (ull N, ull K) {
	if (cache[N][K]) {
		return cache[N][K];
	}
	
	if (K == 1) {
		cache[N][K] = 1;
	} else if (K > N) {
		cache[N][K] = 0;
	} else {
		cache[N][K] = dp(N-1, K-1) + K*(dp(N-1, K));
	}

	return cache[N][K];
}
