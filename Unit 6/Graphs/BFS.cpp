// Construct a directed Graph using BFS 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> breadthFirstSearch(int start, int vertices, vector<vector<int>> &adjMat, vector<int> &bfs){
    vector<bool>visited(vertices, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adjMat[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    vector<vector<int>> adjMatrix(vertices);
    vector<int> bfs;

    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u].push_back(v);
    }

    breadthFirstSearch(0, vertices, adjMatrix, bfs);
    for(int i = 0; i < bfs.size(); i++){
        cout << bfs[i] << " ";
    }
    cout << endl;
    return 0;
}