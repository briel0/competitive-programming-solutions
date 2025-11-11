#include <bits/stdc++.h>
using namespace std;
 
int main(){
  
    string s;
    cin >> s;
    int n = (int)s.size();
    map<char, int> cont;
    for(auto &x : s){
        cont[x]++;
    }
    int imp = 0;
    char meio = '#';
    for(auto &[x, y] : cont){
        if(y & 1){
            imp++;
            meio = x;
        }
    }
    bool c = (n % 2 == 0 && !imp) || (n % 2 && imp == 1);
    string ans = "";
    if(meio != '#'){
        ans = meio;
        cont[meio]--;
    }
    for(auto &[x, y] : cont){
        ans = string(y / 2, x) + ans + string(y / 2, x);
    }
    cout << (c ? ans : "NO SOLUTION");
 
}

