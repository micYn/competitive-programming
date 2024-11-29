#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef long long LL;
const int INF = INT_MAX; // Define infinity as a large value

// Function to implement Dijkstra's algorithm with node restrictions
LL dijkstraWithRestrictions(const vector<vector<pair<int, int>>>& adjList, int source, int destination, const vector<bool>& restrictedNodes) {
    int n = adjList.size(); // Number of nodes in the graph
    vector<LL> dist(n, INF); // Initialize distances to infinity
    dist[source] = 0; // Distance from source to itself is 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue to store vertices ordered by distance
    pq.push({0, source}); // Push source vertex with distance 0 to the priority queue

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second; // Extract the vertex with the smallest distance from the priority queue
        int d = pq.top().first; // Extract its corresponding distance
        pq.pop(); // Remove the vertex from the priority queue

        // If the destination node is reached, return the shortest distance to it
        if (u == destination) return dist[u];

        // If the distance to u is already less than the current distance in the priority queue, skip it
        if (d > dist[u]) continue;

        // Relaxation step: Update distances to all neighbors of u
        for (const auto& neighbor : adjList[u]) {
            int v = neighbor.first; // Destination vertex
            int w = neighbor.second; // Weight of the edge
            // Check if the destination vertex is not restricted and if the distance can be improved via vertex u
            if (!restrictedNodes[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Update distance to vertex v
                pq.push({dist[v], v}); // Push vertex v with updated distance to the priority queue
            }
        }
    }

    // If destination node is not reachable, return -1
    return INF;
}

int main() {
    // Example usage:
    int numCities, numRoads, numQueries, round = 1;
    while(cin >> numCities >> numRoads >> numQueries){
        if(numCities==0&&numRoads==0&&numQueries==0)    break;

        vector<int> feastCost(numCities+1);
        for(int i = 1; i<=numCities;i++){
            cin>>feastCost[i];
        }
        vector<vector<pair<int, int>>> adjList(numCities+1,vector<pair<int, int>>(0));
        for (int i = 1; i <= numRoads; ++i) {
            int u, v, w;
            cin >> u >> v >> w; // Read source, destination, and weight of the edge
            pair<int, int> p1(v, w);
            pair<int, int> p2(u, w);
            adjList[u].push_back(p1);
            adjList[v].push_back(p2);
        }
        
        if(round!=1)    cout<<endl;
        cout<<"Case #"<<round++<<endl;
        while(numQueries--){
            int source, destination; // Source and destination vertices
            cin >> source >> destination; // Read the source and destination vertices

            vector<int> candidate(0);
            int biggerFeast = feastCost[source]>feastCost[destination]?feastCost[source]:feastCost[destination];
            for(int i=1;i<=numCities;i++){
                if(feastCost[i]>=biggerFeast){
                    candidate.push_back(i);
                }
            }
            LL shortestDistance = INF;
            for(int i=0;i<candidate.size();i++){
                vector<bool> restrictedNodes(numCities+1, true);
                for(int j=1;j<=numCities;j++){
                    if(j!=source&&j!=destination&&feastCost[j]<feastCost[candidate[i]])    restrictedNodes[j]=false;
                }
                restrictedNodes[source]=restrictedNodes[candidate[i]] = false;
                LL tmp = dijkstraWithRestrictions(adjList, source, candidate[i], restrictedNodes);
                restrictedNodes[source] = true; restrictedNodes[destination]=false;
                tmp += dijkstraWithRestrictions(adjList, candidate[i], destination, restrictedNodes);
                tmp += feastCost[candidate[i]];
                if(tmp < shortestDistance){
                    shortestDistance = tmp;
                }
            }

            // Output the shortest distance from the source vertex to the destination vertex
            if (shortestDistance != INF) {
                cout << shortestDistance << endl;
            } else {
                cout << "-1" << endl;
            }
        }
        
    }
    return 0; // Return 0 to indicate successful termination
}

