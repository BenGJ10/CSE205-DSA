// Max Heap operations using static Arrays
#include <iostream>
using namespace std;
class MaxHeap{
    int *heap;
    int capacity;   // Total capacity of the heap
    int curr_size;  // Current size of the heap
    
public:
    MaxHeap(int cap){
        this->capacity = cap;
        heap = new int[cap];
        this->curr_size = 0;
    }

    int parent(int i){ return (i - 1) / 2; }
    int leftChild(int i){ return (2 * i + 1); }
    int rightChild(int i){ return (2 * i + 2); }

    void insert(int value){
        if(curr_size == capacity){
            cout << "Heap is full." << endl;
            return; 
        }
        heap[curr_size++] = value;
        int index = curr_size - 1;
        // Heapify-up to restore maxHeap property
        while(index != 0 && heap[parent(index)] < heap[index]){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
    void printHeap(){
        for(int i = 0; i < curr_size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    int capacity;
    cin >> capacity;
    MaxHeap h(capacity);
    for(int i = 0; i < capacity; i++){
        int elem;
        cin >> elem;
        h.insert(elem);
    }
    cout << "Max Heap after insertions: ";
    h.printHeap();
    return 0;
}