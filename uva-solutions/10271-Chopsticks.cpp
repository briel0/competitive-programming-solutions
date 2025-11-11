#include <bits/stdc++.h>
using namespace std;
#define int long long

int k, n;

vector<int> s;

vector<vector<int>> dp;

int calc(int p, int i){
    if(p == k){
        return 0;
    }
    int rs = n - i;
    if(rs < 3 * (k - p)){
        return INT_MAX;
    }
    if(i >= (n - 1)){
        return INT_MAX;
    }
    if(dp[p][i] != -1){
        return dp[p][i];
    }
    int b = (s[i + 1] - s[i]) * (s[i + 1] - s[i]);

    int l = calc(p + 1, i + 2) + b;

    int r = calc(p, i + 1);

    return dp[p][i] = min(l, r);
}

void work(){
    cin >> k >> n;

    k += 8; //k + 8 triplas

    s.resize(n);

    for(int &x : s){
        cin >> x;
    }

    dp = vector<vector<int>>(k + 1, vector<int>(n + 1, -1));

    cout << calc(0, 0) << '\n';

}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        work();
    }
}
