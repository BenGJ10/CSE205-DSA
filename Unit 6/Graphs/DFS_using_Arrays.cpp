// Implement a program that performs Depth First Traversal using Arrays.

#include <iostream>
using namespace std;
#define MAX_VERTICES 100
void addEdge(int adjMat[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adjMat[v][w] = 1;
}
void DFS(int adjMat[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int node) {
    visited[node] = 1;
    cout << node << " ";
    
    for(int i = 0; i < V; i++){
        if(adjMat[node][i] == 1 && !visited[i]){
            DFS(adjMat, visited, V, i);
        }
    }
}
int main(){
    int vertices, edges;
    cin >> vertices;
    cin >> edges;

    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < edges; i++){
        int v, w;
        cin >> v >> w;
        addEdge(adjMatrix, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ": ";
    DFS(adjMatrix, visited, vertices, startVertex);
    cout << endl;
    return 0;
}