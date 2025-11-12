#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(vector<char> &atual, string s){
    string t = "";
    for(int i = atual.size() - 1, j = min(s.size(), atual.size()); j > 0; i--, j--){
        t += atual[i];
    }
    reverse(t.begin(), t.end());
    return t == s;
}

void tira(vector<char> &atual, string s){
    for(int i = 0; i < s.size(); i++){
        atual.pop_back();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    
    string s, t;
    cin >> s >> t;

    vector<char> control;

    for(int i = 0; i < s.size(); i++){
        control.push_back(s[i]);
        if(check(control, t)){
            tira(control, t);
        }
    }

    for(auto &x : control){
        cout << x;
    }
}
