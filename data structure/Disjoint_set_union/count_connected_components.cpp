#include <bits/stdc++.h>
using namespace std;

int parent[100000];
int setSize[100000];


int dsuFind(int a){
    if(parent[a]==a) return a;
    return parent[a] = dsuFind(parent[a]);
}

void dsuUnion(int a, int b) {
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if(leader_a!=leader_b)
    {
        if(setSize[leader_b]<setSize[leader_a])
        {
            swap(leader_a, leader_b);
        }
        parent[leader_b] = leader_a;
        setSize[leader_a]+=setSize[leader_b];
    }
}

int main() {
	// your code goes here
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
    int count=0;
    for(int i=0;i<N;i++){
        if(parent[i]==i){
            count++;
        }
    }
    cout<<count<<endl;
    
    return 0;
}