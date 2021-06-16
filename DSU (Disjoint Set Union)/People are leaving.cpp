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

const int N = 1e6;
int n, m;
int p[N + 5];

void init()
{
    rep(i, 0, N + 1) 
        p[i] = i;
}

int get(int x)
{
    if (x == p[x]) 
        return x;
    
    return p[x] = get(p[x]);
}

void merge(int a)
{
    if (a + 1 > n) 
        p[a] = 0;
    else 
        p[a] = p[a + 1];
}

void solve()
{
    cin >> n >> m;
    
    rep(i, 0, m) {
        char c;
        int x;
        cin >> c >> x;
        
        if (c == '?') {
            x = get(x);
            x == 0 ? cout << -1 << '\n' : cout << x << '\n';
        }
        else 
            merge(x);
    }
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

// Problem Link:- https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/A
