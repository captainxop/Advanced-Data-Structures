// Problem: Given an array a of size n and q queries of two types:
// 1: update the value at position x.
// 2: for a given value x and a range, find the smallest index i in the range, such that a[i] is greater than x.

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for(int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define MOD1 1000000007
#define MOD2 998244353
#define INF  2000000000000000000
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

const int MAXN = 2e5 + 10;
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
	st[node] = max(st[node * 2], st[node * 2 + 1]);
}

int query(int node, int L, int R, int i, int j, int x)
{
	if (st[node] <= x || L > j || R < i) return -1;
	if (i <= L && R <= j) {
		while (L != R) {
			int M = (L + R) / 2;

			if (st[node * 2] > x) {
				node = node * 2;
				R = M;
			}
			else {
				node = node * 2 + 1;
				L = M + 1;
			}
		}

		return L;
	}

	int M = (L + R) / 2;
	int res = query(node * 2, L, M, i, j, x);
	if (res != -1) return res;
	return query(node * 2 + 1, M + 1, R, i, j, x);
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
	st[node] = max(st[node * 2], st[node * 2 + 1]);
}

void solve()
{
	int n;
	cin >> n;

	rep(i, 0, n) cin >> a[i];

	build(1, 0, n - 1);

	int q;
	cin >> q;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int pos, val;
			cin >> pos >> val;
			update(1, 0, n - 1, pos, val);
		}
		else {
			int l, r, x;
			cin >> l >> r >> x;
			cout << query(1, 0, n - 1, l, r, x) << '\n';
		}
	}
}

int main()
{
	fastio;

	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int t = 1;
	//cin >> t;
	while (t--) solve();

	return 0;
}