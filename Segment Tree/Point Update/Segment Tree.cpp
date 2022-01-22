const int MAXN = 2e5 + 5;
int st[4 * MAXN], a[MAXN];

void build(int node, int L, int R)
{
	if (L == R) {
		st[node] = a[L];
		return;
	}

	int M = (L + R) / 2;
	build(node * 2, L, M);
	build(node * 2 + 1, M + 1, R);
	st[node] = merge(st[node * 2], st[node * 2 + 1]); // depends on the query
}

int query(int node, int L, int R, int i, int j)
{
	if (L > j || R < i) return data; // depends on the query
	if (i <= L && R <= j) return st[node];

	int M = (L + R) / 2;
	int left = query(node * 2, L, M, i, j);
	int right = query(node * 2 + 1, M + 1, R, i, j);
	return merge(left, right);
}

void update(int node, int L, int R, int pos, int val)
{
	if (pos < L || pos > R) return;
	if (L == R) {
		st[node] = val;
		a[L] = val;
		return;
	}

	int M = (L + R) / 2;
	update(node * 2, L, M, pos, val);
	update(node * 2 + 1, M + 1, R, pos, val);
	st[node] = merge(st[node * 2], st[node * 2 + 1]);
}