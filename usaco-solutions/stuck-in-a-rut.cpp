#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<tuple<char, int, int>> s(n);

    for(auto &[a, b, c] : s){
        cin >> a >> b >> c;
    }

    vector<array<int, 3>> e;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            auto [di, xi, yi] = s[i];
            auto [dj, xj, yj] = s[j];

            if(di == dj || di == 'N'){
                continue;
            }

            if(xj <= xi || yj >= yi){
                continue;
            }

            int dife = xj - xi, difn = yi - yj;

            if(dife < difn){
                e.push_back({difn, j, i});
            }
            else if(difn < dife){
                e.push_back({dife, i, j});
            }

        }
    }
    
    sort(e.begin(), e.end());

    vector<int> ans(n, -1);

    for(auto &[a, b, c] : e){

        if(ans[b] != -1){
            continue;
        }

        auto [db, xb, yb] = s[b];
        auto [dc, xc, yc] = s[c];

        int disc;

        if(dc == 'E'){
            disc = xb - xc;
        }
        else{
            disc = yb - yc;
        }
        if(ans[c] == -1 || ans[c] > disc){
            ans[b] = a;
        }
    }

    for(auto &x : ans){
        cout << (x == -1 ? "Infinity" : to_string(x)) << '\n';
    }
}

