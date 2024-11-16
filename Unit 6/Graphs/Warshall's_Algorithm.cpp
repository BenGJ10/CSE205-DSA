#include <iostream>
#include <vector>
using namespace std;

void warshallAlgorithm(vector<vector<int>> &reach, int vertices){
    for(int k = 0; k < vertices; k++){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
}

int main(){
    int vertices;
    cin >> vertices;
    vector<vector<int>> graph(vertices, vector<int>(vertices));
    vector<vector<int>> reach(vertices, vector<int>(vertices));
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cin >> graph[i][j];
            reach[i][j] = graph[i][j];
        }
    }
    int u, v;
    cin >> u >> v;
    warshallAlgorithm(reach, vertices);
    
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }

    if(reach[u][v] == 1){
        cout << "Path Exists" << endl;
    } else{
        cout << "Path does not Exist" << endl;
    }
    return 0;
}