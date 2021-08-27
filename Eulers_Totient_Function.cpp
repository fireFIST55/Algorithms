#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    vector<int>phi(n + 1);

    for(int i = 1; i<=n; i+=1)
        phi[i] = i;

    for(int i = 2; i<=n; i += 1){
        if(phi[i] == i){

            for(int j = i; j<=n; j += i){
                phi[j] -= (phi[j]/i);

                // Here initially phi[j] == j. So is !(j%i) then what it means is actually there is a factor i in j. So, all the number that i divides will
                // have gcd of atleast i. As all of them have factor i in them. So, our job here is to remove them. j/i denotes the number of number which has
                // i as factor. Now we have to get rid of them hence phi[j] -= phi[j]/i;
            }
        }
    }

    return 0;
}