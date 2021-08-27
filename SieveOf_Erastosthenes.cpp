#include<bits/stdc++.h>
using namespace std;
class sieve{
public:
    vector<bool>isPrime;
    sieve(int n){
        isPrime.resize(n + 1, true);

        for(int i = 2; i<=n; i+=1){
            if(isPrime[i]){
                for(int j = i*i; j<=n; j+=i)    isPrime[i] = false;
            }
        }
    }
};

int main(void){
    int n;
    cin>>n;
    sieve p(n);
}