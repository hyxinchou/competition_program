#include <bits/stdc++.h>

const int nxm = int(1e3) + 7;

int n, m;
long long a[nxm], b[nxm];

int main() {
	std::cin >> n >> m;
	// dp[i][diff]
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	std::vector<std::vector<long long>> dp(n * m, std::vector<long long> (n * m, 1E18));
	dp[0][1] = a[0]; // num'(' - num')'
	for (int i = 1; i < n * m; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j + 1] = std::min(dp[i][j + 1], dp[i - 1][j] + a[i % n]);
			if (j) {
				dp[i][j - 1] = std::min(dp[i][j - 1], dp[i - 1][j] + b[i % n]);
			}
		}
	}
	std::cout << dp[n * m - 1][0] << "\n";
	return 0;
}