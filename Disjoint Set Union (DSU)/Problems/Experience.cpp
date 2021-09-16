#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second

#define rep(i, a, b) for(int i = a; i < b; i++)
#define repR(i, a, b) for (int i = a; i >= b; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vs vector<string>
#define vb vector<bool>

#define vpii vector<pii>
#define vpll vector<pll>

#define mod 1000000007
#define ps(x,y) fixed << setprecision(y) << x
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)

const int N = 3 * 1e5;
int p[N], r[N], points[N], val[N];

void init()
{
    rep(i, 0, N) {
        p[i] = i;
        r[i] = 1;
        points[i] = 0;
        val[i] = 0;
    }
}

int find_set(int x)
{
    if (x == p[x])
        return x;

    return find_set(p[x]);
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);

        p[b] = a;
        r[a] += r[b];
        val[b] = points[a]; // To Store Point of leader a before merging with b
    }
}

int GetPoints(int x)
{
    if (x == p[x])
        return points[x];

    return points[x] - val[x] + GetPoints(p[x]); // current points of x - points before joining
}

void solve()
{
    int n, q;
    cin >> n >> q;

    while (q-- > 0) {
        string s; cin >> s;

        if (s == "join") {
            int x, y; cin >> x >> y;
            union_set(x, y);
        }
        else if (s == "add") {
            int x, v; cin >> x >> v;
            x = find_set(x);
            points[x] += v;
        }
        else {
            int x; cin >> x;
            cout << GetPoints(x) << '\n';
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

    init();

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}

// Problem Link:- https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C