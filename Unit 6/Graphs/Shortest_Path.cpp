// Find shortest path and distance from source node to end using BFS

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_VERTICES 100

void addEdge(int adjMatrix[][MAX_VERTICES], int source, int dest){
    adjMatrix[source][dest] = 1;
    adjMatrix[dest][source] = 1;
}

bool breadthFirstSearch(int adjMatrix[][MAX_VERTICES], int src, int dest, int vertices, int pred[], int distance[]){
    vector<bool> visited(vertices, false);
    queue<int> q;
    for(int i = 0; i < vertices; i++){
        distance[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] = true;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adjMatrix[node]){
            if(!visited[it]){
                visited[it] = true;
                distance[it] = distance[node] + 1;
                pred[it] = node;
                q.push(it);

                if(it == dest){
                    return true;
                }
            }
        }
    }
    return false;
}

void printShortestDistance(int adjMatrix[][MAX_VERTICES], int src, int dest, int v, int pred[], int dist[]){
    if(!breadthFirstSearch(adjMatrix, src, dest, v, pred, dist)){
        cout << "No path exists between " << src <<" and " << dest << endl;
        return;
    }
    cout << "Shortest path length is: " << dist[dest] << endl;
    cout << "Path is: ";
    int elem = dest;
    int path[MAX_VERTICES];
    int pathIndex = 0;

    // Traversing from end node to its predecessor
    while(elem != -1){
        path[pathIndex++] = elem;
        elem = pred[elem];
    }

    for(int i = pathIndex - 1; i >= 0; i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        addEdge(adjMatrix, u, v);
    }
    int source, dest;
    cin >> source >> dest;
    
    int predecessor[vertices];
    int distance[vertices];
    if (breadthFirstSearch(adjMatrix, source, dest, vertices, predecessor, distance))
        printShortestDistance(adjMatrix, source, dest, vertices, predecessor, distance);
   
    return 0;
}