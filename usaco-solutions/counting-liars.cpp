#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, char>> s(n);

    for(auto &[a, b] : s){
        cin >> b >> a;
    }

    sort(s.begin(), s.end());

    int g[n] = {};
    
    for(int i = 0; i < n; i++){
        g[i] += s[i].second == 'G';
        if(i > 0) g[i] += g[i - 1];
    }

    int l[n] = {};

    for(int i = n - 1; i >= 0; i--){
        l[i] += s[i].second == 'L';
        if(i < n - 1) l[i] += l[i + 1];
    }

    int ans = 1;

    for(int i = 0; i < n; i++){
        int temp = g[i];
        if(i < n - 1){
            temp += l[i + 1];
        }
        ans = max(ans, temp);
    }
    cout << n - ans << '\n';
}
