#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, w, h, s;
    cin >> n >> w >> h >> s;

    char c;
    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        char atual;
        cin >> atual;

        for(int j = 0; j < h; j++){
            string p;
            cin >> p;
            p = '.' + p + '.';
            int acnt = 0;
            for(int k = 0; k < w + 1; k++){
                acnt += p[k] != p[k + 1]; 
            }
            if(acnt == 0) continue;
            int op = (s + acnt - 1) / acnt;
            if(op <= ans){
                ans = op;
                c = atual;
            }
        }
    }
    while(ans--) cout << c;
}
