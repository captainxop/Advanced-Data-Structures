const int N = 1e5;
int p[N + 5], r[N + 5]; // parent array and rank array

void init()
{
    for (int i = 0; i < N; i++)
        p[i] = i, r[i] = 1;
}

int find_set(int x)
{
    if (x == p[x]) 
        return x;
    
    return p[x] = find_set(p[x]);
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
    }
}
