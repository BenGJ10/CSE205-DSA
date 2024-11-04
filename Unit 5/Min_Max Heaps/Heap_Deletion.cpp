// Implementation of deletion in a max heap using an array.
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
        swap(heap[largest], heap[i]);
        maxHeapify(heap, size, largest);
    }
}
int deleteRoot(int heap[], int &size){
    if(size <= 0)   return -1;
    int root = heap[0];
    // Swapping root with the last element
    heap[0] = heap[size - 1];
    size--;

    // Heapify down from the root to restore max-heap property
    maxHeapify(heap, size, 0);
    
    return root;
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
    cout << "Heap before deletion: ";
    print(heap, size);
    int deletedVal = deleteRoot(heap, size);

    cout << "Heap after deletion of root value " << deletedVal << ": ";
    print(heap, size);
    return 0;
}