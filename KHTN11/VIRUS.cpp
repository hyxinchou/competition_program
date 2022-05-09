#include <bits/stdc++.h>

int n;
int a[1000];
int b[1000];

int main() {
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	std::vector<int> C(n, 0);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
		++C[u];
		++C[v];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
	}
	std::vector<int> p(n);
	std::iota(p.begin(), p.end(), 0);
	int ans = 1E9;
	do {
		int ret = 0;
		std::vector<int> f = C;
		// for (int i = 0; i < n; ++i) {
		// 	std::cout << p[i] << " \n"[i == n - 1];
		// }
		// std::cout << "---\n";
		for (int i = 0; i < n; ++i) {
			if (f[p[i]] & 1) {
				ret += b[p[i]];
			} else {
				ret += a[p[i]];
			}
			for (int j = 0; j < int(E[p[i]].size()); ++j) {
				--f[E[p[i]][j]];
			}
			// std::cout << ret << " ";
		}
		// std::cout << "\n";
		ans = std::min(ans, ret);
	} while (std::next_permutation(p.begin(), p.end()));
	std::cout << ans << "\n";
	return 0;
}