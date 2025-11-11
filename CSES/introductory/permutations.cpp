#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "NO SOLUTION" << '\n';
        return 0;
    }
    for(int a = 2; a > 0; a--){
        for(int i = a; i <= n; i += 2){
            cout << i << ' ';
        }
    }
}

