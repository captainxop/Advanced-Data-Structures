// O(log(n)) per Query 

const int MAX_N = 2e5 + 10;
const int MAX_LOG = 25;
ll RSQ[MAX_N][MAX_LOG];
int a[MAX_N];

void build(int n)
{
    for (int i = 0; i < n; i++) {
        RSQ[i][0] = a[i];
    }
    
    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            RSQ[i][j] = RSQ[i][j - 1] + RSQ[i + (1 << (j - 1))][j - 1];
        }
    }
}

ll query(int L, int R)
{
    ll sum = 0LL;
    for (int j = MAX_LOG; j >= 0; j--) { 
        if ((1 << j) <= R - L + 1) {
            sum += RSQ[L][j];
            L += (1 << j);
        }
    }
    
    return sum;
}

// Problem:- https://cses.fi/problemset/task/1646
