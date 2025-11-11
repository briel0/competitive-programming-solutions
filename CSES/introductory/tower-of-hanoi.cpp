#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> ans;
 
void hanoi(int n, int origem, int temp, int destino){
    if(n == 1){
        ans.push_back({origem, destino});
        return;
    }
    hanoi(n - 1, origem, destino, temp);
    ans.push_back({origem, destino});
    hanoi(n - 1, temp, origem, destino);
}
 
int main(){
    
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << ans.size() << '\n';
    for(auto &[x, y] : ans){
        cout << x << ' ' << y << '\n';
    }
 
}

