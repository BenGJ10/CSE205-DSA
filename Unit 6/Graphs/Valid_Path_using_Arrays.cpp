#include <iostream>
using namespace std;
void depthFirstSearch(int node, int vertices, int adjMatrix[10][10], bool visited[]){
    visited[node] = true;
    for(int i = 0; i < vertices; i++){
        if(!visited[i] && adjMatrix[node][i]){
            depthFirstSearch(i, vertices, adjMatrix, visited);
        }
    }
}
bool hasPath(int start, int end, int adjMatrix[10][10], int vertices){
    bool visited[10] = {false};
    depthFirstSearch(start, vertices, adjMatrix, visited);
    return visited[end];
}
int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    int adjMatrix[10][10];
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }
    int start, end;
    cin >> start >> end;

    if(hasPath(start, end, adjMatrix, vertices)){
        cout << "There is a path from " << start << " to " << end << endl;
    } else{
        cout << "There is no path from " << start << " to " << end << endl;
    }
    return 0;
}