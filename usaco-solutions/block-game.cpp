#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;

    int ans[26] = {};

    for(int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;

        int a[26] = {}, b[26] = {};

        for(auto &x : s){
            a[x - 'a']++;
        }

        for(auto &x : t){
            b[x - 'a']++;
        }
        
        for(int j = 0; j < 27; j++){
            ans[j] += max(a[j], b[j]);
        }

    }
    for(int i = 0; i < 26; i++){
        cout << ans[i] << '\n';
    }
}

