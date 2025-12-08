#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    double n, k, d, s;
    cin >> n >> k >> d >> s;

    double de = d * n - s * k;

    double ans = de / (n - k);

    if(de < 0 || ans > 100.0){
        cout << "impossible\n";
        return 0;
    }
    
    cout << fixed << setprecision(7) << ans << '\n';

}
