template <typename T> class SegTree {
public:
	int n;
	T e;
	vector<T> st;

	SegTree(int _n, T _e = T()) {
		n = _n;
		e = _e;
		st.resize(4 * n + 10);
	}

	T merge(const T &l, const T &r)
	{
		return min(l, r); // min segment tree
	}

	template<typename U> void build(U &arr, int i, int l, int r)
	{
		if (l == r) {
			st[i] = T(arr[l]);
			return;
		}

		int mid = l + (r - l) / 2;
		build(arr, i << 1, l, mid);
		build(arr, i << 1 | 1, mid + 1, r);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	template<typename U> void Update(int i, int l, int r, int idx, U val)
	{
		if (l == r) {
			st[i] = T(val);
			return;
		}

		int mid = l + (r - l) / 2;
		if (idx <=  mid)
			Update(i << 1, l, mid, idx, val);
		else
			Update(i << 1 | 1, mid + 1, r, idx, val);

		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	}

	T Query(int i, int l, int r, int ql, int qr)
	{
		if (ql > r || qr < l)
			return e;
		if (l >= ql && r <= qr) {
			return st[i];
		}

		int mid = l + (r - l) / 2;
		T x = Query(i << 1, l, mid, ql, qr);
		T y = Query(i << 1 | 1, mid + 1, r, ql, qr);

		return merge(x, y);
	}

	template<typename U> void update(int idx, U val)
	{
		Update(1, 0, n - 1, idx, val);
	}

	T query(int ql, int qr)
	{
		return Query(1, 0, n - 1, ql, qr);
	}
};