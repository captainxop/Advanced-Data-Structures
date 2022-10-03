struct DSU {
	vector<int> p, r; // parent and rank array
 
	DSU(int n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		r.assign(n + 1, 1);
	}
 
	int find_set(int x)
	{
		if (x == p[x]) return x;
		return p[x] = find_set(p[x]);
	}
 
	bool union_set(int a, int b)
	{
		a = find_set(a); b = find_set(b);
		if (a == b) return false;
		if (r[a] < r[b]) swap(a, b);
		p[b] = a;
		r[a] += r[b];
		return true;
	}
};
