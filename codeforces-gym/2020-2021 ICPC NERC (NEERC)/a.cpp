#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n == 1996 || n == 1997 || n == 2000 || n == 2007 || n == 2008
    || n == 2013 || n == 2018){
        cout << "SPbSU";
    }
    else if(n == 2006){
        cout << "PetrSU, ITMO";
    }
    else{
        cout << "ITMO";
    }

}
