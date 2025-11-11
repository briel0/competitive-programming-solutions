#include <bits/stdc++.h>
using namespace std;
 
int main(){
  
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> ans;
    while(next_permutation(s.begin(), s.end())){
        ans.insert(s);
    }
    ans.insert(s);
    cout << ans.size() << '\n';
    for(auto &x : ans) cout << x << '\n';
    
}

