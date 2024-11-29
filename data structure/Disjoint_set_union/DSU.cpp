#include <bits/stdc++.h>
using namespace std;

int parent[100000];


int dsuFind(int a){
    //Complete this function to implement the find functionality in a DSU
    if(parent[a]==a){
        return a;
    }
    else{
        return dsuFind(parent[a]);
    }
}

void dsuUnion(int a, int b) {
    // Complete this function to implement the union functionality in a DSU
    int leader_a = dsuFind(a);
    int leader_b = dsuFind(b);
    if(leader_a == leader_b){
        return;
    }else{
        parent[leader_b] = leader_a;
    }
}
int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        parent[i] = i;
    }
    for(int i=0; i<m; i++)
    {
        string command;
        cin>>command;
        if(command == "union")
        {
            int a, b;
            cin>>a>>b;
            dsuUnion(a, b);
        }
        else if(command == "find"){
            int a;
            cin>>a;
            cout<<dsuFind(a)<<endl;
        }
    }
}