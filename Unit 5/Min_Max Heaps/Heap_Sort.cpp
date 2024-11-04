// Implementing Heap Sort
// T.C -> O(N log N)
#include <iostream>
using namespace std;
void maxHeapify(int heap[], int size, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < size && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != i){
        swap(heap[i], heap[largest]);
        maxHeapify(heap, size, largest);
    }
}
void heapSort(int heap[], int size){
    // Building the max heap
    for(int i = size / 2 - 1; i>= 0; i--){
        maxHeapify(heap, size, i);
    }
    // Extracting elements one by one
    for(int i = size - 1; i >= 0; i--){
        swap(heap[i], heap[0]);
        // Applying the heapify on reduced heap
        maxHeapify(heap, i, 0);
    }
}
void print(int heap[], int size){
    for(int i = 0; i < size; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main(){
    int size;
    cin >> size;
    int heap[size];
    for(int i = 0; i < size; i++){
        cin >> heap[i];
    }
    cout << "Heap before sorting: ";
    print(heap, size);
    heapSort(heap, size);
    cout << "Heap after sorting: ";
    print(heap, size);
    return 0;
}