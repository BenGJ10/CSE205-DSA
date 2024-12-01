// Delete Minimum element from MinHeap

#include <iostream>
using namespace std;
void minHeapify(int heap[], int size, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && heap[left] < smallest){
        smallest = left;
    }
    if(right < size && heap[right] < smallest){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        minHeapify(heap, size, smallest);
    }
}
void buildMinHeap(int heap[], int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        minHeapify(heap, size, i);
    }
}

void deleteMin(int heap[], int &size){
    heap[0] = heap[size - 1];
    size--;
    minHeapify(heap, size, 0);
}
void printMinHeap(int heap[], int size) {
    for(int i = 0; i < size; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main(){
    
    return 0;
}