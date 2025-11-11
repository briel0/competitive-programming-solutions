#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    long long n, r = 0;
    cin >> n;
    long long s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        if(i > 0 && s[i] <= s[i - 1]){
            long long a = s[i - 1] - s[i];
            s[i] += a;
            r += a;
        }
    }
    cout << r;
}

