#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, fav = -1, N = 1e4;
vector<int> a, dp;

int calc(int tamanho){
    if(tamanho == 0){
        return 0;
    }

    if(tamanho > N){
        int pegou = (tamanho - N + fav - 1) / fav;
        int restou = tamanho - fav * pegou;
        return calc(restou) + pegou * dp[fav];
    }

    if(dp[tamanho] != -1){
        return dp[tamanho];
    }

    int ans = LLONG_MAX;
    for(int i = 1; i < tamanho; i++){
        int atual = calc(tamanho - i) + calc(i);
        ans = min(ans, atual);
    }
    return dp[tamanho] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int q;
    cin >> n >> q;

    dp.assign(1e4 + 5, -1);

    for(int i = 1; i <= n; i++){
        cin >> dp[i];
        if(fav == -1 || dp[i] * fav < dp[fav] * i){
            fav = i;
        }
    }

    for(int i = 0; i < q; i++){
        int k;
        cin >> k;
        cout << calc(k) << '\n';
    }
}
