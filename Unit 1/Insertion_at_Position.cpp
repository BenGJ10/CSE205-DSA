// Insert an element at a particular position in an array
#include <iostream>
using namespace std;
void insertElement(int arr[], int &n, int pos, int elem){
    for(int i = n; i > pos; i--){
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    n++;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int pos, elem;
    cin >> pos;
    cin >> elem;
    cout << "Array before Insertion: ";
    printArray(arr, size);
    insertElement(arr, size, pos, elem);
    printArray(arr, size);
    return 0;
}