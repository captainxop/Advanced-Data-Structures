const int MAXN = (int)2e5 + 10;
const int MAXQ = (int)2e5 + 10;
int BLOCK_SIZE;

inline int64_t hilbertOrder(int x, int y, int pow, int rotate)
{
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow - 1);
	int seg = (x < hpow) ? (
	              (y < hpow) ? 0 : 3
	          ) : (
	              (y < hpow) ? 1 : 2
	          );
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = hilbertOrder(nx, ny, pow - 1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query {
	int l, r, idx;
	int64_t ord;

	inline void calcOrder() {
		ord = hilbertOrder(l, r, 21, 0);
	}
};

inline bool operator<(const Query &a, const Query &b)
{
	return a.ord < b.ord;
}

int n, q;
Query qr[MAXN];
int arr[MAXN], freq[(int)1e6 + 10];
long long ans[MAXN];
long long curr_ans;

inline void add(int x)
{
	curr_ans -= 1LL * freq[x] * freq[x] * x;
	freq[x]++;
	curr_ans += 1LL * freq[x] * freq[x] * x;
}

inline void remove(int x)
{
	curr_ans -= 1LL * freq[x] * freq[x] * x;
	freq[x]--;
	curr_ans += 1LL * freq[x] * freq[x] * x;
}

void mo()
{
	BLOCK_SIZE = sqrt(n) + 1;
	sort(qr, qr + q);
	int l = 0, r = -1;
	curr_ans = 0;

	for (int i = 0; i < q; i++) {
		while (r < qr[i].r) add(arr[++r]);
		while (l > qr[i].l) add(arr[--l]);
		while (r > qr[i].r) remove(arr[r--]);
		while (l < qr[i].l) remove(arr[l++]);

		ans[qr[i].idx] = curr_ans;
	}
}

// Problem: https://codeforces.com/contest/86/problem/D