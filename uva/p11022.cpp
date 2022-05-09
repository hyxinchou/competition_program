#include <bits/stdc++.h>

using namespace std;

constexpr int nxm = 80 + 7;

char s[nxm];
int dp[nxm][nxm];

vector<int> prefix_function(string ss) {
	int n = (int)ss.size();
	vector<int> pi(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && ss[i] != ss[j]) {
			j = pi[j - 1];
		}
		if (ss[i] == ss[j]) {
			++j;
		}
		pi[i] = j;
	}
	return pi;
}

int calc(int l, int r) {
	assert(l < r);
	if (dp[l][r] != -1) {
		return dp[l][r];
	}
	string new_s = "";
	for (int i = l; i < r; ++i) {
		new_s += s[i];
	}
	auto prefix_array = prefix_function(new_s);
	int len = (int)new_s.size();
	int res = (int)1e9;
	if (len % (len - prefix_array[len - 1]) == 0) {
		res = len - prefix_array[len - 1];
		// res = min(res, calc(l, l + res));
		// if (!l) {
			// printf("%d\n", res);
		// }
		int new_r = res;
		for (int i = l; i < l + new_r - 1; ++i) {
			res = min(res, calc(l, i + 1) + calc(i + 1, l + new_r));
			// if (!l) {
			// 	printf("%d %d %d %d %d %d\n", l, i, i + 1, l + res, calc(l, i), calc(i + 1, l + res));
			// }
		}
		// if (!l) {
			// 	printf("%d\n\n", res);
			// for (int i = 0; i < len; ++i) {
			// 	printf("%d ", prefix_array[i]);
			// }
			// printf("\n");
		// }
	}
	for (int k = l; k < r - 1; ++k) {
		res = min(res, calc(l, k + 1) + calc(k + 1, r));
	}
	return dp[l][r] = res;
}

int main() {
	while (scanf("%s", s)) {
		if (s[0] == '*') {
			break;
		}
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < nxm; ++i) {
			dp[i][i] = 1;
		}
		calc(0, strlen(s));
		// printf("%d\n", strlen(s));
		// for (int i = 0; i < strlen(s); ++i) {
		// 	for (int j = i; j < strlen(s); ++j) {
		// 		printf("%d %d %d\n", i, j, dp[i][j]);
		// 	}
		// 	printf("\n");
		// }
		printf("%d\n", dp[0][strlen(s)]);
	}
	return 0;
}