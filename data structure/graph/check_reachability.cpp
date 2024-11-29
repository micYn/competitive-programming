#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& visited, vector<vector<int> >& adjList){
    visited[node]=true;
    int length = adjList[node].size();
    for(int i=0;i<length;i++){
        if(!visited[adjList[node][i]])
        dfs(adjList[node][i], visited, adjList);
    }
}

void dfsHandler(int numNodes, vector<vector<int> >& adjList){
    vector<bool> visited(numNodes+1, false);
    dfs(1, visited, adjList);
    for(int i = 1; i <= numNodes; i++) {
        if(visited[i]) // A node is reachable if it is marked visited
            cout << i << " ";
    }
}
int main() {
	// your code goes here
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    vector<vector<int> > adjList(numNodes+1);
    int u, v;
    while(cin>>u>>v){
        adjList[u].push_back(v);
    }

    dfsHandler(numNodes, adjList);


    return 0;
}
