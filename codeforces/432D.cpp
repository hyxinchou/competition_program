#include <bits/stdc++.h>

using namespace std;

constexpr int nxm = int(1e5) + 7;

int n;
int now;
char s[nxm];
vector<int> answer;
int counting[nxm];

vector<int> prefix_function() {
	vector<int> pi(n);
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
	scanf("%s", s);
	n = strlen(s);
	auto prefix_array = prefix_function();
	for (int i = 0; i < n; ++i) {
		++counting[prefix_array[i]];
	}
	for (int i = n - 1; i; --i) {
		counting[prefix_array[i - 1]] += counting[i];
	}
	for (int i = 1; i <= n; ++i) {
		++counting[i];
	}
	now = prefix_array[n - 1];
	// now : https://1drv.ms/u/s!AiHG0kGxqqf5hQIOJCJnWp5-7bSE
	while (now) {
		answer.push_back(now);
		now = prefix_array[now - 1];
	}
	answer.push_back(n);
	sort(answer.begin(), answer.end());
	printf("%d\n", (int)answer.size());
	for (int i = 0; i < (int)answer.size(); ++i) {
		printf("%d %d\n", answer[i], counting[answer[i]]);
	}
	return 0;
}