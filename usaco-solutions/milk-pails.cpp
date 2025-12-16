#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int ans = 0;

    for(int j = 0; j <= m; j += x){
        for(int i = 0; i <= m; i += y){
            if(i + j <= m && i + j > ans){
                ans = i + j;
            }
        }
    }
    cout << ans;
}

