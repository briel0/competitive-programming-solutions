#include <bits/stdc++.h>
using namespace std;
 
int main(){

    long long n, r = 0;
    cin >> n;
    long long q = ((n*n) + n) / 2;
    for(int i = 0; i < (n - 1); i++){
        long long p;
        cin >> p;
        r += p;
    }
    cout << q - r;
}
