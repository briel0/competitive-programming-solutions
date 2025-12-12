#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    while((1ll << ans) < (n * 8ll * 1E6)){
        ans++;
    }
    cout << ans << '\n';
}
