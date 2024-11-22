// Maximum Flow Using Floyd-Warshall 

#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 100
#define INF -1
void floydWarshall(int capacity[SIZE][SIZE], int n){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(capacity[i][k] != INF && capacity[k][j] != INF){
                    capacity[i][j] = max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
                }
            }
        }
    }
}
int main(){
    int vertices, edges;
    cin >> vertices >> edges;
    int capacity[SIZE][SIZE];
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            capacity[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        capacity[u][v] = max(capacity[u][v], w); 
    }
    floydWarshall(capacity, vertices);
    int source, sink;
    cin >> source >> sink;

     if (capacity[source][sink] == INF) {
        cout << "No path exists between " << source << " and " << sink << endl;
    } else {
        cout << "Maximum flow from " << source << " to " << sink << " is: " << capacity[source][sink] << endl;
    }
    return 0;
}