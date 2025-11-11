#include <bits/stdc++.h>
using namespace std;
 
string table[8];
int ans = 0;
 
void constroi(int x, int d1[], int d2[], int columns[]){
    if(x == 8){
        ans++;
        return;
    }
    for(int y = 0; y < 8; y++){
        if(columns[y] || d1[x + y] || d2[x - y + 7] || table[x][y] == '*'){
            continue;
        }
        columns[y] = d1[x + y] = d2[x - y + 7] = 1;
        constroi(x + 1, d1, d2, columns);
        columns[y] = d1[x + y] = d2[x - y + 7] = 0;         
 
    }
}
 
int main(){
  
    for(auto &x : table){
        cin >> x;
    }
 
    int x = 0, diag1[15] = {}, diag2[15] = {}, colunas[8] = {};
    constroi(x, diag1, diag2, colunas);
    cout << ans;
 
}

