#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    string s;
    cin >> s;
    int r = 1, g = 1;
    for(int i = 1; i < s.size(); i++){
        g = (s[i] == s[i - 1] ? g + 1 : 1);
        r = max(r, g);
    }
    cout << r;
}
