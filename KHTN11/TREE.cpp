#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

int main() {
	int n;
	std::cin >> n;
	std::vector<std::array<int, 3>> edges;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		edges.push_back({w, u, v});
	}
	int q;
	std::cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		edges.push_back({w, u, v});
		std::sort(edges.begin(), edges.end());
		DSU dsu(n);
		int64_t answer = 0;
		for (int i = 0; i < int(edges.size()); ++i) {
			if (dsu.merge(edges[i][1], edges[i][2])) {
				answer += 1LL * edges[i][0];
			}
		}
		std::cout << answer << "\n";
	}
	return 0;
}