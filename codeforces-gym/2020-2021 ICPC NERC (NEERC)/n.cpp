#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[55][55];

int calc(int n, int k){
    if(k > n){
        return 0;
    }
    if(n == 0 || k == 0){
        return 1;
    }
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    return dp[n][k] = calc(n - 1, k) + calc(n - 1, k - 1);
}

int burnside(int n, int i){
    //distintos considerando simetria
    // = (todos + palindromos) / 2
    int todos = calc(n, i);
    int palindromos = 0;

    if(n % 2 == 0){
        if(i % 2 == 0){
            palindromos = calc(n / 2, i / 2);
        }
    }
    else{
        palindromos = calc(n / 2, i / 2);
    }
    return (todos + palindromos) / 2;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 0; i <= 50; i++){
        for(int j = 0; j <= 50; j++){
            dp[i][j] = -1;
        }
    }

    int needs[k + 1] = {};

    for(int i = 0; i <= k; i++){
        int l = i, r = k - i;

        if(l > n || r > n) continue;

        if(l == r){
            needs[l] = max(needs[l], 2ll);
        }
        else{
            needs[l] = max(needs[l], 1ll);
            needs[r] = max(needs[r], 1ll);
        }
    }

    int ans = 0;

    for(int i = 0; i <= k; i++){
        ans += needs[i] * burnside(n, i);
    }
    
    cout << ans;
}
