#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
 
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int ans = i*i * (i*i - 1) / 2 - 4 * (i - 1) * (i - 2);
        cout << ans << '\n';
    }
 
}
