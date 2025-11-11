#include <bits/stdc++.h>
using namespace std;
 
int n;
vector<long long> pesos;
 
long long busca(int atual, long long sum1, long long sum2){
    if(atual == n){
        return abs(sum1 - sum2);
    }
    return min(busca(atual + 1, sum1 + pesos[atual], sum2), 
    busca(atual + 1, sum1, sum2 + pesos[atual]));
}
 
int main(){
    
    cin >> n;
    pesos.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pesos[i];
    }   
    cout << busca(0, 0, 0);
}

