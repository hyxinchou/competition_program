#include <bits/stdc++.h>

int a[3][3][3];
int f[3];

int calc(std::string s) {
	// std::cout << "[" << s << "]\n";
	int n = int(s.size());
	std::vector<std::vector<int>> dp(n + 7, std::vector<int> (3, 0x3f3f3f3f));
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	// dp[2][]
	for (int i = 2; i < n - 1; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				int fx, fy, ffx = 0, ffy = 0;
				if (s[i] == '?') {
					fx = j;
					ffx = f[j];
				} else if (int(s[i] - '0') == j) {
					fx = j;
				} else continue;
				if (s[i + 1] == '?') {
					fy = k;
					ffy = f[k];
				} else if (int(s[i + 1] - '0') == k) {
					fy = k;
				} else continue;
				for (int t = 0; t < 3; ++t) {
					for (int tt = 0; tt < 3; ++tt) {
						dp[i + 1][t] = std::min(dp[i + 1][t], dp[i][tt] + a[fx][fy][t] + ffx + ffy);
					}
					// std::cerr << i + 1 << " " << fx << " " << fy << " " << t << " " << dp[i + 1][t] << "\n";
				}
			}
		}
	}
	return std::min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 3; ++k) {
				std::cin >> a[i][j][k];
			}
		}
	}
	for (int i = 0; i < 3; ++i) {
		std::cin >> f[i];
	}
	for (int i = 0; i < Q; ++i) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int id;
			char c;
			std::cin >> id >> c;
			--id;
			s[id] = c;
		} else {
			int l, r;
			std::cin >> l >> r;
			--l, --r;
			std::string new_s = "";
			for (int j = l; j <= r; ++j) {
				new_s += s[j];
			}
			std::cout << calc(new_s) << "\n";
		}
	}
	return 0;
}