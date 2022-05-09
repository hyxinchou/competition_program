#include <bits/stdc++.h>

int n, m, k;

int main() {
	std::cin >> n >> m >> k;
	std::vector<std::vector<int>> g2d(n, std::vector<int> (m, -1));
	std::vector<std::vector<int>> g2d2(n, std::vector<int> (m, -1));
	for (int i = 0; i < k; ++i) {
		int x, y, c;
		std::cin >> x >> y >> c;
		g2d[x - 1][y - 1] = c;
	}
	std::function<std::pair<int, int>(int)> get_id = [&](int x) {
		int xx = x / m;
		int yy = x % m;
		return std::make_pair(xx, yy);
	};
	std::function<bool()> check = [&]() {
		bool ok = true;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = 0; j < m - 1; ++j) {
				int ret = 0;
				ret += (g2d2[i][j] == 0 ? 1 : 0);
				ret += (g2d2[i + 1][j] == 0 ? 1 : 0);
				ret += (g2d2[i][j + 1] == 0 ? 1 : 0);
				ret += (g2d2[i + 1][j + 1] == 0 ? 1 : 0);
				if (ret & 1) {
					ok = false;
				}
			}
		}
		return ok;
	};
	int ans = 0;
	std::function<void()> sub_1 = [&]() {
		int fx = n * m;
		for (int mask = 0; mask < (1 << fx); ++mask) {
			bool con = false;
			for (int i = 0; i < fx; ++i) {
				std::pair<int, int> loc = get_id(i);
				if (g2d[loc.first][loc.second] == -1) {
					g2d2[loc.first][loc.second] = (mask >> i & 1 ? 0 : 1);
				} else {
					int d = (mask >> i & 1 ? 0 : 1);
					if (d == g2d[loc.first][loc.second]) {
						g2d2[loc.first][loc.second] = g2d[loc.first][loc.second];
					} else {
						con = true;
					}
				}
			}
			if (check() && !con) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < m; ++j) {
						std::cout << g2d2[i][j] << " \n"[j == m - 1];
					}
				}
				std::cout << "\n";
				++ans;
			}
		}
	};
	sub_1();
	std::cout << ans << "\n";
	return 0;
}