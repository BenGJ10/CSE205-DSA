// Given a graph with vertices and edges, your task is to write a program that determines if 
// there is a valid path from a specified starting vertex to an ending vertex.

#include <iostream>
#include <vector>
using namespace std;
void depthFirstSearch(int node, vector<vector<int>> &adjMat, vector<bool> &visited){
    visited[node] = true;

    for(auto it : adjMat[node]){
        if(!visited[it]){
            depthFirstSearch(it, adjMat, visited);
        }
    }
}
bool hasPath(int start, int end, vector<vector<int>> &adjMat, int vertices){
    vector<bool> visited(vertices, false);
    depthFirstSearch(start, adjMat, visited);
    return visited[end];    
}
int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adjMatrix(vertices);
    for(int i = 0; i < edges; i++){
        int u , v;
        cin >> u >> v;
        adjMatrix[u].push_back(v);
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