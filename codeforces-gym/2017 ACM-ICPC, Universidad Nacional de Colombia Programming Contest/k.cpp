#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int binexp(int base, int expo){
    int res = 1;
    while(expo){
        if(expo & 1){
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        expo >>= 1;
    }
    return res;
}

vector<int> combina(vector<int> a, vector<int> b){
    vector<int> novo(14);
    for(int i = 1; i <= 13; i++){
        novo[i] = a[i] + b[i];
    }
    return novo;
}

struct SegmentTree {
    vector<vector<int>> original, seg;
    int n;

    SegmentTree(int size) : original(size + 1), seg(4 * size + 1){
        n = size;
    }

    void build(int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l == r){
            seg[node] = original[l];
        }
        else{
            int mid = (l + r) / 2;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            seg[node] = combina(seg[2 * node], seg[2 * node + 1]);
        }
    }

    void update(int idx, vector<int> _new, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l == r){
            seg[node] = _new;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid){
            update(idx, _new, 2 * node, l, mid);
        }
        else{
            update(idx, _new, 2 * node + 1, mid + 1, r);
        }
        seg[node] = combina(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> query(int a, int b, int node = 1, int l = 1, int r = 0){
        if(r == 0){
            r = n;
        }
        if(l > b || r < a){
            vector<int> neutro(14);
            return neutro;
        }
        if(l >= a && r <= b){
            return seg[node];
        }
        int mid = (l + r) / 2;
        return combina(query(a, b, 2 * node, l, mid), query(a, b, 2 * node + 1, mid + 1, r));
    }
};

int tempo = 0;
const int N = 1e5 + 5;
vector<int> adj[N], tin, tout, ordem;

void dfs(int v, int p){
    ordem.push_back(v);
    tin[v] = tempo++;
    for(int &x : adj[v]){
        if(x != p){
            dfs(x, v);
        }
    }
    tout[v] = tempo;
}

vector<int> fact(int p){
    vector<int> info(14);
    for(int j = 2; j * j <= p; j++){
        while(p % j == 0){
            info[j]++;
            p /= j;
        }
    }
    if(p != 1){
        info[p]++;
    }
    return info;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a++, b++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    tin.resize(n + 1), tout.resize(n + 1);

    vector<vector<int>> info(n + 1);

    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        info[i] = fact(p);
    }

    dfs(1, 1);

    SegmentTree seg(n);

    for(int i = 1; i <= n; i++){
        seg.original[i] = info[ordem[i - 1]];
    }

    seg.build();

    int q;
    cin >> q;

    for(int i = 1; i <= q; i++){
        string s;
        cin >> s;
        if(s == "RAND"){
            int p;
            cin >> p;
            p++;
            vector<int> res = seg.query(tin[p] + 1, tout[p]);

            int prod = 1, num = 1;
            for(int &x : res){
                prod = ((prod % MOD) * ((x + 1) % MOD)) % MOD;
            }
            for(int j = 1; j <= 13; j++){
                num = ((num % MOD) * (binexp(j, res[j]) % MOD)) % MOD;
            }
            cout << num << ' ' << prod << '\n';
            continue;
        }
        int no, x;
        cin >> no >> x;
        no++;
        vector<int> temp = seg.query(tin[no] + 1, tin[no] + 1);
        vector<int> outro = fact(x);
        seg.update(tin[no] + 1, combina(temp, outro));
    }

}
