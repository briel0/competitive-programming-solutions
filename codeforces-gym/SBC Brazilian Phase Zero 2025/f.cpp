#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<int> s;

int dp[8005][1005][5];

int calc(int value, int i, int elements){
    if(i == n){
        return dp[value][i][elements] = (value == 0 && elements == 0);
    }
    if(dp[value][i][elements] != -1){
        return dp[value][i][elements];
    }

    int ans = calc(value, i + 1, elements);
    if(value - s[i] >= 0 && elements >= 1){
        ans += calc(value - s[i], i + 1, elements - 1);
    }

    return dp[value][i][elements] = ans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    s.resize(n);

    for(int &x : s){
        cin >> x;
        x += 1000;
    }

    memset(dp, -1, sizeof(dp));

    int q;
    cin >> q;
    while(q--){
        int v;
        cin >> v;
        cout << calc(v + 4000, 0, 4) << '\n';
    }

}
