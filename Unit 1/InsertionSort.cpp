// Implement Insertion sort and sort element in descending order
#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> &v, int n){
    for(int i = 1; i <= n - 1; i++){
        int j = i;
        while(j > 0 && v[j] > v[j - 1]){
            swap(v[j], v[j - 1]);
            j--;
        }
        cout << "After Iteration " << i << ": ";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
int main(){
    cout << "Enter the size of the vector: ";
    int size;
    cin >> size;
    cout << "Enter the elements: ";
    vector<int> v1(size);
    for(int i = 0; i < size; i++){
        cin >> v1[i];
    }
    cout << "Initial order: ";
    for(int i = 0; i < size; i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    insertionSort(v1, size);
    cout << "Sorted order: ";
    for(int i = 0; i < size; i++){
        cout << v1[i] << " ";
    }
    return 0;
}