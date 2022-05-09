#include <bits/stdc++.h>

using namespace std;

constexpr int nxm = (int)1e2 + 7;

int n;
int test;
char s[nxm];

vector<int> prefix_function() {
	vector<int> pi(n, 0);
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] ^ s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		pi[i] = j;
	}
	return pi;
}

int main() {
	scanf("%d", &test);
	while (test--) {
		scanf("%s", s);
		n = strlen(s);
		auto prefix_array = prefix_function();
		if (n % (n - prefix_array[n - 1]) == 0) {
			printf("%d\n", n - prefix_array[n - 1]);
		} else {
			printf("%d\n", n);
		}
		if (test) {
			printf("\n");
		}
	}
	return 0;
}