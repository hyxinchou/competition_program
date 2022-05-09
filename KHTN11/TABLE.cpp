#include <bits/stdc++.h>

const int nxm = int(1e5) + 7;

int n;
int a[nxm];
int c[4];

int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		++c[a[i]];
	}
	std::vector<int> ans(n, 2);
	bool have_ans = false;
	if (~c[2] & 1) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == 2) {
				if (cnt & 1) {
					ans[i] = 3;
				} else {
					ans[i] = 1;
				}
				++cnt;
			}
		}
		have_ans = true;
	} else {
		int cnt = 0;
		bool f_change = false;
		int f_change_is = -1;
		for (int i = 0; i < n; ++i) {
			if (a[i] != 2 && !f_change) {
				if (a[i] == 1) {
					ans[i] = 3;
				} else {
					ans[i] = 1;
				}
				f_change = true;
				f_change_is = ans[i];
			}
		}
		if (f_change) {
			have_ans = true;
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == 2) {
				if (f_change_is == 1) {
					ans[i] = 3;
				} else {
					ans[i] = 1;
				}
				a[i] = -1;
				break;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[i] == 2) {
				if (cnt & 1) {
					ans[i] = 3;
				} else {
					ans[i] = 1;
				}
				++cnt;
			}
		}
	}
	if (!have_ans) {
		std::cout << "0\n";
	} else {
		for (int i = 0; i < n; ++i) {
			std::cout << ans[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}