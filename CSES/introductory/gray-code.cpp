#include <bits/stdc++.h>
using namespace std;
#define tam(x) (int)x.size()
 
int main(){
 
    int n;
    cin >> n;
    vector<string> ans;
    unordered_map<string, bool> control;
    string s = string(n, '0');
    control[s] = 1;
    ans.push_back(s);
    for(int i = 0; i < ((1 << n) - 1); i++){
        for(int j = 0; j < n; j++){
            string copia = s;
            copia[j] = (copia[j] == '0' ? '1' : '0');
            if(!control[copia]){
                ans.push_back(copia);
                control[copia] = 1;
                s = copia;
                break;
            }
        }
    }
    for(auto &x : ans){
        cout << x << '\n';
    }
}

