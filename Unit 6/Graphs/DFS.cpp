// Construct a directed Graph using DFS

#include <iostream>
#include <vector>
using namespace std;
vector<int> depthFirstSearch(int node, vector<bool> &visited, vector<vector<int>> &adjMat, vector<int> &dfs){
    visited[node] = true;
    dfs.push_back(node);

    for(auto it : adjMat[node]){
        if(!visited[it]){
            depthFirstSearch(it, visited, adjMat, dfs);
        }
    }
    return dfs;
}
int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adjMatrix(vertices);
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u].push_back(v);
    }
    vector<bool> visited(vertices, false);
    vector<int> dfs;
    depthFirstSearch(0, visited, adjMatrix, dfs);
    for(int i = 0; i < dfs.size(); i++){
        cout << dfs[i] << " ";
    }
    return 0;
}