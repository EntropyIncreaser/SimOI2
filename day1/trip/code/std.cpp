#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>

#include <algorithm>
#include <limits>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 110, INF = 1000000000, L = 18;

struct Mat {
	int g[N][N];
	
	Mat() { memset(g, -1, sizeof(g)); }
	
	Mat(const Mat& x) { memcpy(g, x.g, sizeof(g)); }
	
	const int* operator[](int k) const { return g[k]; }
	int* operator[](int k) { return g[k]; }
	
	Mat operator*(const Mat& rhs) const;
};

int n, m;
int p[N], c[N], tmp[N];
int mx[N][N], dp[N][N * N];

Mat tr[L];

int* operator*=(int* arr, const Mat& rhs);

int main() {
	int cc, t;
	scanf("%d%d%d%d", &n, &m, &cc, &t);
	for (int u = 1; u <= n; ++u) {
		scanf("%d%d", &p[u], &c[u]);
		c[u] = min(cc, c[u]);
	}
	for (int u = 1; u <= n; ++u)
		tr[0][u][u] = 0;
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		tr[0][u][v] = max(tr[0][u][v], w);
	}
	for (int k = 1; k < L; ++k)
		tr[k] = tr[k - 1] * tr[k - 1];
	for (int u = 1; u <= n; ++u) {
		memset(tmp, -1, sizeof(tmp));
		tmp[u] = 0;
		for (int k = 0; k < L; ++k)
			if ((c[u] >> k) & 1)
				tmp *= tr[k];
		memcpy(mx[u], tmp, sizeof(tmp));
	}
	for (int q = 0; q <= n * n; ++q)
		for (int u = 1; u <= n; ++u) {
			if (q < p[u])
				continue;
			for (int v = 1; v <= n; ++v)
				if (mx[u][v] != -1)
					dp[u][q] = max(dp[u][q], min(dp[v][q - p[u]] + mx[u][v], INF));
		}
	while (t--) {
		int s, q, d;
		scanf("%d%d%d", &s, &q, &d);
		int bd = lower_bound(dp[s], dp[s] + n * n + 1, d) - dp[s];
		if (bd > q)
			puts("-1");
		else
			printf("%d\n", q - bd);
	}
	return 0;
}

int* operator*=(int* arr, const Mat& rhs) {
	static int tmp[N];
	memset(tmp, -1, sizeof(tmp));
	for (int u = 1; u <= n; ++u)
		for (int v = 1; v <= n; ++v)
			if (arr[u] != -1 && rhs[u][v] != -1)
				tmp[v] = max(tmp[v], min(arr[u] + rhs[u][v], INF));
	memcpy(arr, tmp, sizeof(tmp));
	return arr;
}

Mat Mat::operator*(const Mat& rhs) const {
	Mat ret = Mat();
	for (int u = 1; u <= n; ++u)
		for (int v = 1; v <= n; ++v)
			for (int w = 1; w <= n; ++w)
				if (g[u][v] != -1 && g[v][w] != -1)
					ret[u][w] = max(ret[u][w], min(g[u][v] + g[v][w], INF));
	return ret;
}
