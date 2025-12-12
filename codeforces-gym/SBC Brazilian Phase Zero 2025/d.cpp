#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    string s, t;
    cin >> n >> s >> t;

    double a = 0, d = 0;

    for(int i = 0; i < n; i++){
        a += (s[i] == '*');
        d += (s[i] == '*' && t[i] != '*');
    }

    double ans = d / a;
    cout << fixed << setprecision(2) << ans;
}
