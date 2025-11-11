#include <bits/stdc++.h>
using namespace std;
 
const long long MOD = 1e9 + 7;
 
long long fe(long long a, long long b){
    
    long long r = 1;
    while(b > 0){
        if(b & 1){
            r = r * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}
 
int main(){
 
    long long n;
    cin >> n;
    cout << fe(2, n);
    
}

