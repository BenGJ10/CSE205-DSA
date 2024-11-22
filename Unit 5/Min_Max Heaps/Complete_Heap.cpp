// Perform both Insertion and Deletion in Heaps
// Time complexity of heapify operation -> O(log N)
// Complete Binary Tree -> All levels except possibly the last are fully filled, and the last is filled left to right
#include <iostream>
using namespace std;
void maxHeapify(int heap[], int size, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if(left < size && heap[left] > heap[largest]){
        largest = left;
    }
    if(right < size && heap[right] > heap[largest]){
        largest = right;
    }
    if(largest != index){
        swap(heap[largest], heap[index]);
        maxHeapify(heap, size, largest);
    }
}
int parent(int i){
    return (i - 1) / 2;
}
void insertElements(int heap[], int &size, int val){
    heap[size] = val;
    int index = size;
    size++;
    while(index > 0 && heap[index] > heap[parent(index)]){
        swap(heap[index], heap[parent(index)]);
        index = parent(index);
    }
}
void deleteFromHeap(int heap[], int &size){
    heap[0] = heap[size - 1];
    size--;
    maxHeapify(heap, size, 0);
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
    int count  = 0;
    for(int i = 0; i < size; i++){
        int val;
        cin >> val;
        insertElements(heap, count, val);
    }
    cout << "Heap before deletion: ";
    print(heap, count);
    deleteFromHeap(heap, count);
    cout << "Heap after deleting the root element: ";
    print(heap, count);
    return 0;
}