#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

struct Range {
	int l, r;
	
	Range() : l(-1), r(-1) {}
	
	Range(int l, int r) : l(l), r(r) {}
	
	Range operator-() const { return Range(-r, -l); }
	
	Range operator+(const Range& rhs) const { return Range(l + rhs.l, r + rhs.r); }
};

const int N = 110, L = 510;

int m, sz, n;

char name[L];
Range rg[256];
char s[N][L];

int read(char*& p) {
	while (*p == ' ')
		++p;
	if (*p == 'n') {
		++p;
		return n;
	}
	int cur = 0;
	while (*p >= '0' && *p <= '9')
		cur = cur * 10 + *p++ - '0';
	return cur;
}

void solve() {
	scanf("%d%d%d\n", &m, &sz, &n);
	for (int i = 1; i <= m; ++i)
		gets(s[i]);
	int cnt = 0, badc = 0;
	fill(rg, rg + 256, Range());
	bool re = false;
	for (int i = 1; i <= m; ++i) {
		char* p = s[i];
		char cur;
		int sign = 1;
		Range tmp(0, 0);
		switch (*p) {
		case 'F':
			p += 2;
			cur = *p;
			++p;
			if (rg[cur].l != -1) {
				puts("ERR");
				return;
			}
			rg[cur].l = read(p);
			rg[cur].r = read(p);
			name[++cnt] = cur;
			if (rg[cur].l > rg[cur].r)
				++badc;
			break;
		case 'a':
			p += 2;
			sign = 1;
			if (*p == '-') {
				sign = -1;
				++p;
			}
			tmp = tmp + ((sign == 1) ? rg[*p] : -rg[*p]);
			if (rg[*p].l == -1) {
				puts("ERR");
				return;
			}
			++p;
			while (*p != ']') {
				sign = *p == '+' ? 1 : -1;
				++p;
				tmp = tmp + (sign == 1 ? rg[*p] : -rg[*p]);
				if (rg[*p].l == -1) {
					puts("ERR");
					return;
				}
				++p;
			}
			if ((tmp.l < 0 || tmp.r >= sz) && badc == 0)
				re = true;
			break;
		case 'E':
			if (cnt == 0) {
				puts("ERR");
				return;
			}
			if (rg[name[cnt]].l > rg[name[cnt]].r)
				--badc;
			rg[name[cnt]] = Range();
			--cnt;
			break;
		}
	}
	if (cnt) {
		puts("ERR");
		return;
	}
	if (re)
		puts("RE");
	else
		puts("AC");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
