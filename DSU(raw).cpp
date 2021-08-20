#include<bits/stdc++.h>
using namespace std;
int nodes, vertices;
vector<int>parent(nodes+1);

void makeSet(int u){
    parent[u] = u;
}

int findRepresentative(int u){
    if(u==parent[u])    return u;
    else return findRepresentative(parent[u]);
}

void unionSet(int a, int b){
     a = findRepresentative(a);
     b = findRepresentative(b);

     if(a!=b)   parent[b] = a;
}

int main(void){
    cin>>nodes>>vertices;

    for(int i = 1; i<=nodes; i++)
        makeSet(i);
    
    for(int i = 0; i<vertices; i++){
        int a, b;
        cin>>a>>b;
        unionSet(a, b);
    }

    return 0;
}
