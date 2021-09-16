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

const int N = 50000;
int p[N + 5], r[N + 5];

void init()
{
    rep(i, 0, N + 1) {
        p[i] = i, r[i] = 1;
    }
}

int get(int x)
{
    if (x == p[x])
        return x;

    return p[x] = get(p[x]);
}

void union_set(int a, int b)
{
    a = get(a);
    b = get(b);

    if (a != b) {
        if (r[a] < r[b])
            swap(a, b);

        p[b] = a;
        r[a] += r[b];
    }
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<string, pii>> q;
    vector<string> ans;

    rep(i, 0, m) {
        int u, v; cin >> u >> v;
    }

    rep(i, 0, k) {
        string s;
        int u, v;
        cin >> s >> u >> v;
        q.pb(mp(s, mp(u, v)));
    }

    reverse(all(q));

    for (auto it : q) {
        string s = it.ff;
        int u = it.ss.ff, v = it.ss.ss;

        if (s == "ask") {
            u = get(u);
            v = get(v);

            if (u == v)
                ans.pb("YES");
            else
                ans.pb("NO");
        }
        else
            union_set(u, v);
    }

    reverse(all(ans));

    for (auto s : ans)
        cout << s << '\n';
}

int main()
{
    fastio;

    /*#ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
         freopen("output.txt","w",stdout);
         #endif*/

    init();

    int t = 1;
    //cin >> t;
    while (t--) solve();

    return 0;
}

//Problem Link:- https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

// Idea is to traverse the query in reverse and treat "cut" as "adding" edge
// since its mentioned that after all cut operations the graph is empty.