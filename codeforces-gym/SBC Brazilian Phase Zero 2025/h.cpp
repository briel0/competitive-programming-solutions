#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    if(n == 1) {
        cout << "1\n";
        return 0;
    }

    if(__builtin_popcountll(n) == 1){
        cout << n - 1 << '\n';
        return 0;
    }
    
    int msb = 60;

    while((n & (1ll << msb)) == 0){
        msb--;
    }

    int l = msb, r = 0;

    int ans = (1ll << msb) + 1;

    l--, r++;

    while(r < l){
        if(ans + (1ll << l) + (1ll << r) <= n){
            ans += (1ll << l) + (1ll << r);
        }
        l--, r++;
    }
    if(msb % 2 == 0){
        if(ans + (1ll << l) <= n){
            ans += (1ll << l);
        }
    }
    cout << ans;
}
