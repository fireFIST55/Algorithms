#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define endl '\n'

vector<int>vc(100), tre(100);

int fn(int index){
    int sm = 0;
    while(index > 0){
        sm += tre[index];
        index -= (index & -index);
    }

    return sm;
}

void update(int index, int val, int n){
    while(index <= n){
        tre[index] += val;
        index += (index & -index);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin>> n;
    
    for(int i = 1; i<=n; i += 1){
        cin>> vc[i];
        update(i, vc[i], n);
    }

    int query;
    cin>> query;

    while(query--){
        int l, r;
        cin>> l>> r;
        int sm = fn(r) - fn(l - 1);
        cout<<sm<<endl;
    }

    return 0;
}

// Any number can be represented as summations of power of two. For example 7 = 2^2 + 2^1 + 2^0. Now if we want to have the sum of all the elements from index
// 1 to index 7 we can add 7th index's value and the n 6 - 5 and then 4 - 1. This will serve our perpoose. If we take a closer look at the intervals between
// them (7 - 7 + 1) = 1, (6 - 5 + 1) = 2 = 2^1. (4 - 1 + 1) = 4 = 2^2 which is in another word is the represntation of the binary representation of 7.