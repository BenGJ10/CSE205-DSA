// Max Heap insertion using dynamic Arrays
#include <iostream>
#include <vector>
using namespace std;
class MaxHeap{
    vector<int> heap;

    void heapifyUp(int index){
        while(index > 0 && heap[parent(index)] < heap[index]){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

public:
    int parent(int i){ return (i - 1) / 2; }
    int leftChild(int i){ return 2 * i + 1; }
    int rightChild(int i){ return 2 * i + 2; }

    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void printHeap(){
        for(int i : heap){
            cout << i << " ";
        }
        cout << endl;
    }
};
int main(){
    MaxHeap h;
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++){
        cin >> arr[i];
        h.insert(arr[i]);
    }
    cout << "Max Heap after insertion: ";
    h.printHeap();
    return 0;
}