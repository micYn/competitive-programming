#include <bits/stdc++.h>
using namespace std;
int parent[10000];
int setSize[10000];
int dsuFind(int a){
    if(parent[a]==a)    return a;
    else    return parent[a] = dsuFind(parent[a]);
}
void dsuUnion(int a, int b){
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if(leader_a == leader_b){
        return;
    }
    else{
        if(setSize[leader_b] > setSize[leader_a]){
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;
        setSize[leader_a] += setSize[leader_b];
    }
}
int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        parent[i] = i;
        setSize[i] = 1;
    }
    int a,b;
    while(M--){
        cin>>a>>b;
        dsuUnion(a,b);
    }
    int max = 0;
    for(int i=0;i<N;i++){
        if(setSize[i]>max){
            max = setSize[i];
        }
    }
    cout<<max<<endl;
}