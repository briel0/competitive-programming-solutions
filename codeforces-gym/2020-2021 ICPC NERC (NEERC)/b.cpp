#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int a, x, b, y, t;
    cin >> a >> x >> b >> y >> t;

    int u = a + max(0ll, t - 30) * x * 21;
    int d = b + max(0ll, t - 45) * y * 21;
    cout << u << ' ' << d;

}
