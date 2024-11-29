#include <bits/stdc++.h>
using namespace std;
void getMinimumServers(int n, vector<pair<int, int> >& serverConnections){
        // Complete the code
        int numNodes=n;
        vector<vector<int> > adjList(numNodes+1);
        int numConnections = serverConnections.size();
        for(int i=0;i<numConnections;i++){
            adjList[serverConnections[i].first].push_back(serverConnections[i].second);
            adjList[serverConnections[i].second].push_back(serverConnections[i].first);
        }
        int distance[numNodes+1];   for(int i=0;i<=numNodes;i++){distance[i]=-2;}
        queue<int> que;
        vector<bool> visited(numNodes+1, false);
        visited[1] = true;
        que.push(1);
        distance[1] = 0;
        while(!que.empty()){
            int tmp = que.front();
            int dis = distance[tmp];
            que.pop();
            for(int i=0;i<adjList[tmp].size();i++){
                if(!visited[adjList[tmp][i]]){
                    visited[adjList[tmp][i]] = true;
                    distance[adjList[tmp][i]] = dis + 1;
                    que.push(adjList[tmp][i]);
                }
            }
        }
        for(int i=1;i<=numNodes;i++){
            cout<<distance[i]+1<<" ";
        }
}
int main(){
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    vector<pair<int, int> > serverConnections;
    int u,v;
    while(cin>>u>>v){
        pair<int, int> tmp = make_pair(u,v);
        serverConnections.push_back(tmp);
    }
    getMinimumServers(numNodes,serverConnections);
    return 0;
}