const int MAXN = (int)2e5 + 10;
const int MAXQ = (int)2e5 + 10;
int BLOCK_SIZE;

struct Query {
	int l, r, idx;
};

Query qr[MAXQ];
int n, q;
int arr[MAXN], freq[(int)1e6 + 10];
long long ans[MAXQ];
long long curr_ans;

bool comp(const Query &a, const Query &b)
{
	if (a.l / BLOCK_SIZE != b.l / BLOCK_SIZE) return a.l < b.l;
	else return (a.l / BLOCK_SIZE & 1) ? a.r < b.r: a.r > b.r;
}

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
	sort(qr, qr + q, comp);
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