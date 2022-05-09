#include <bits/stdc++.h>

int n, k, v;

int main() {
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	bool ok = false;
	bool two = false;
	std::function<void()> go = [&]() {
		std::vector<int> p(300007, -1);
		std::vector<int> Pre(300007, -1);
		std::vector<int> dp;
		for (int i = 0; i < n; ++i) {
			int l = std::lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
			if (l < int(dp.size())) {
				dp[l] = a[i];
				Pre[a[i]] = (l - 1 >= 0 ? dp[l - 1] : -1);
				p[a[i]] = l;
			} else {
				// std::cerr << "<<" << a[i] << "\n";
				p[a[i]] = int(dp.size());
				dp.push_back(a[i]);
				Pre[a[i]] = (int(dp.size()) - 2 >= 0 ? dp[int(dp.size()) - 2] : -1);
			}
		}
		// for (int i = 1; i <= n; ++i) {
		// 	std::cerr << p[i] << " \n"[i == n];
		// }
		// std::cout << int(dp.size()) << "\n";
		int len_lis = int(dp.size());
		std::vector<int> path;
		// for (int i = 0; i < n; ++i) {
		// 	std::cerr << "[" << a[i] << " " << Pre[a[i]] << "]\n";
		// }
		for (int i = n - 1; i >= 0; --i) {
			if (p[a[i]] == len_lis - 1) {
				// std::cerr << a[i] << "\n";
				int curr = a[i];
				path.push_back(curr);
				while (true) {
					curr = Pre[curr];
					if (curr == -1) {
						break;
					}
					path.push_back(curr);
				}
				std::reverse(path.begin(), path.end());
				break;
			}
		}
		// std::cout << "____\n";
		// for (auto v : path) {
		// 	std::cerr << v << " ";
		// }
		// std::cout << "\n";
		// std::cerr << len_lis << "\n";
		if (two) {
			std::reverse(path.begin(), path.end());
			std::reverse(a.begin(), a.end());
		}
		if (len_lis >= k) {
			ok = true;
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				if (a[i] == path[cnt]) {
					std::cout << i + 1 << " ";
					++cnt;
				}
				if (cnt >= k) {
					break;	
				}
			}
		}
	};
	go();
	if (!ok) {
		two = true;
		std::reverse(a.begin(), a.end());
		go();
	}
	std::cout << "\n";
	return 0;
}