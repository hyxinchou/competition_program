#include <bits/stdc++.h>
using namespace std;

constexpr int nxm = int(5e3) + 7;

int N, M, Q;
int a[nxm][nxm];
int f[nxm][nxm];

int dp(int l, int r) {
	if (l > r) return 0;
	if (f[l][r] != -1) return f[l][r];
	return f[l][r] = a[l][r] + dp(l + 1, r) + dp(l, r - 1) - dp(l + 1, r - 1);
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 0; i < M; ++i) {
		int L, R;
		scanf("%d%d", &L, &R);
		++a[L][R];
	}
	memset(f, -1, sizeof(f));
	dp(1, N);
	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = i; j <= N; ++j) {
	// 		cerr << f[i][j] << " \n"[j == N];
	// 	}
	// }
	for (int i = 0; i < Q; ++i) {
		int p, q;
		scanf("%d%d", &p, &q);
		printf("%d\n", f[p][q]);
	}
	return 0;
}