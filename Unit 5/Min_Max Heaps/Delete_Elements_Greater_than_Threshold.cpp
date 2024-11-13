/* Mithu is given an array of integers and a threshold value. He wants to create a max-heap from the 
   given array and then remove all elements from the heap that are greater than the given threshold. 
   After performing these operations, Mithu wants to display the remaining elements in the max-heap. */

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
// Build the max-heap from the array
void buildMaxHeap(int heap[], int size){
    for(int i = size / 2 - 1; i >= 0; i--){
        maxHeapify(heap, size, i);
    }
}
void deleteElementsGreaterThanThreshold(int heap[], int &size, int tValue){
    int i = 0;
    while(i < size){
        if(heap[i] > tValue){
            heap[i] = heap[size - 1];
            size--;
        }
        else{
            i++;
        }
    }
}
void printMaxHeap(int heap[], int size) {
    for(int i = 0; i < size; i++){
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main(){
    int size, tValue;
    cin >> size;
    int heap[size];
    for(int i = 0; i < size; i++){
        cin >> heap[i];
    }
    cin >> tValue;
    buildMaxHeap(heap, size);
    cout << "Heap before deleting Values greater than Threshold value: ";
    printMaxHeap(heap, size);
    deleteElementsGreaterThanThreshold(heap, size, tValue);
    cout << "Heap after deleting Values greater than Threshold value: ";
    printMaxHeap(heap, size);
}