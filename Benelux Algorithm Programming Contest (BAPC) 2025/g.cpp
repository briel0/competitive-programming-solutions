#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
map<string, bool> c;

vector<int> dp;

bool calc(int pos){
    if(pos == s.size()){
        return true;
    }
    if(dp[pos] != -1){
        return dp[pos];
    }
    bool res = 0;
    for(int i = 6; i <= 10; i++){
        if((pos + i - 1) >= s.size()){
            continue;
        }
        string atual = s.substr(pos, i);
        if(c[atual]){
            res |= calc(pos + i);
        }
    }
    return dp[pos] = res;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        c[temp] = 1;
    }

    dp.assign(s.size() + 1, -1);

    cout << (calc(0) ? "yes" : "no");

}

