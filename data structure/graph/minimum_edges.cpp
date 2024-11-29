#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    vector<vector<int> > adjList(numNodes+1);
    int u,v;
    while(cin>>u>>v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    adjList[u].pop_back();
    adjList[v].pop_back();
    int startNode = u, endNode = v;
    vector<bool> visited(numNodes+1, false);
    vector<int> distance(numNodes+1, -1);

    visited[startNode] = true;
    distance[startNode] = 0;
    queue<int> que;
    que.push(startNode);
    while(!que.empty()){
        int tmp = que.front();
        int dis = distance[tmp];
        que.pop();
        for(int i=0;i<adjList[tmp].size();i++){
            if(!visited[adjList[tmp][i]]){
                visited[adjList[tmp][i]] = true;
                distance[adjList[tmp][i]] = dis+1;
                que.push(adjList[tmp][i]);
            }
        }
    }
    cout<<distance[endNode]<<endl;

    return 0;
}