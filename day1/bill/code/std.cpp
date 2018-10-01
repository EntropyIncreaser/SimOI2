#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1000050;

int n;
char s[N];
int digits[N];

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int l = strlen(s);
		for (int i = 0; i < l; ++i)
			digits[i] += s[l - i - 1] - '0';
	}
	int top = 0;
	for (int i = 0; i < N - 1; ++i) {
		if (digits[i])
			top = i;
		digits[i + 1] += digits[i] / 10;
		digits[i] %= 10;
	}
	for (int i = top; i >= 0; --i)
		putchar(digits[i] + '0');
	putchar('\n');
	return 0;
}
