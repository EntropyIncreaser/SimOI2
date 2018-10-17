#include <cstdio>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

const int L = 60, X = 1000010, P = 1000000007;

int fc;
ll p[L];
int k[L], inv[L], dec[L];
ll x;

struct Table {
	int a[X], b[X];

	int& operator[](ll k) { return k <= x / k ? a[k] : b[x / k]; }
	int operator[](ll k) const { return k <= x / k ? a[k] : b[x / k]; }
};

Table a, prob;
int ans = 0;

void dfs(int ind, ll prod);

int main() {
	int t;
	scanf("%lld%d", &x, &t);
	int y = 1;
	for (; y * (ll)y <= x; ++y)
		if (x % y == 0)
			scanf("%d", &a[y]);
	while (y * (ll)y >= x)
		--y;
	for (; y; --y)
		if (x % y == 0)
			scanf("%d", &a[x / y]);
	prob[x] = 1;
	ll tmp = x;
	for (y = 2; y * (ll)y <= x; ++y)
		if (x % y == 0) {
			int cnt = 0;
			++fc;
			p[fc] = y;
			while (x % y == 0) {
				x /= y;
				++cnt;
			}
			k[fc] = cnt;
		}
	if (x != 1) {
		p[++fc] = x;
		k[fc] = 1;
	}
	x = tmp;
	inv[1] = 1;
	for (int i = 2; i < L; ++i)
		inv[i] = -(P / i) * (ll)inv[P % i] % P + P;
	dfs(1, x);
	printf("%d\n", ans);
	while (--t) {
		ll v;
		int w;
		scanf("%lld%d", &v, &w);
		int diff = (w - a[v]) % P;
		if (diff < 0)
			diff += P;
		a[v] = w;
		ans = (ans + diff * (ll)prob[v]) % P;
		printf("%d\n", ans);
	}
	return 0;
}

void dfs(int ind, ll prod) {
	if (ind == fc + 1) {
		ans = (ans + prob[prod] * (ll)a[prod]) % P;
		int cc = fc - count(dec + 1, dec + fc + 1, 0);
		if (cc == 0)
			return;
		int tr = inv[cc];
		for (int i = 1; i <= fc; ++i)
			if (dec[i])
				prob[prod / p[i]] = (prob[prod / p[i]] + prob[prod] * (ll)tr) % P;
		return;
	}
	for (dec[ind] = k[ind]; dec[ind] >= 0; --dec[ind]) {
		dfs(ind + 1, prod);
		prod /= p[ind];
	}
}
