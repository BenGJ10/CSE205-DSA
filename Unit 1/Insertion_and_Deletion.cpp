// Insert an element at a given index and remove a particular element from an array
#include <iostream>
using namespace std;
void arrayTraversal(int arr[], int n){
    cout << "Current Array elements: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertElement(int arr[], int n, int elem, int pos){
    int i;
    n++;
    for(i = n; i >= pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = elem;
}
void deleteElement(int arr[], int n, int elem){
    int i;
    for(i = 0; i < n; i++){
        if(arr[i] == elem){
            break;
        }
    }
    if(i < n){
        n--;
        for(int j = i; j < n; j++){
            arr[j] = arr[j + 1]; 
        }
    }
}
int main(){

    return 0;
}