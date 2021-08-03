// O(1) per Query for Idempotent Functions like min/max/gcd.

const int MAX_N = 2e5 + 10; 
const int MAX_LOG = 25;
int RMQ[MAX_N][MAX_LOG];
int LOG[MAX_N];
int a[MAX_N];

void init()
{
    LOG[1] = 0;
    for (int i = 2; i < MAX_N; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
}

void build(int n)
{
    for (int i = 0; i < n; i++) {
        RMQ[i][0] = a[i];
    }
    
    for (int j = 1; j < MAX_LOG; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            RMQ[i][j] = min(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R)
{
    int j = LOG[R - L + 1];
    return min(RMQ[L][j], RMQ[R - (1 << j) + 1][j]);
}

//Problem:- https://www.spoj.com/problems/RMQSQ/
//Solution:- https://ideone.com/JoWkbL
