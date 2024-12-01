// Implementing BFS using Arrays
#include <iostream>
using namespace std;
void breadthFirstSearch(int start, int vertices, int adjMatrix[10][10], int bfs[], int &bfsSize){
    bool visited[10] = {false};
    int queue[10];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while(front < rear){
        int node = queue[front++];
        bfs[rear++] = node;
        bfsSize++;
        
        for(int i = 0; i < vertices; i++){
            if(!visited[i] && adjMatrix[node][i] == 1){
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}
int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    int adjMatrix[10][10];
    int bfs[10];
    int bfsSize = 0;
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
    }
    breadthFirstSearch(0, vertices, adjMatrix, bfs, bfsSize);
    for(int i = 0; i < bfsSize; i++){
        cout << bfs[i] << " ";
    }
    cout << endl;
    return 0;
}