/* Mia is working with a Min Heap to manage a collection of integers. She wants to efficiently perform the 
   following operations:
   Insert integers into a Min Heap.
   Display the current state of the Min Heap.
   Delete the smallest prime number from the heap and display the updated heap.
   Your task is to help Mia implement these functionalities in her program. */

#include <iostream>
using namespace std;
int parent(int i){ return (i - 1) / 2; }
void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < size && heap[left] < heap[smallest]){
        smallest = left;
    }
    if(right < size && heap[right] < heap[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        minHeapify(heap, size, smallest);
    }
}
void insertElement(int heap[], int* size, int val){
    heap[*size] = val;
    int index = (*size);
    (*size)++;

    while(index > 0 && heap[parent(index)] < heap[index]){
        swap(heap[parent(index)], heap[index]);
        index = parent(index);
    } 
}
void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
bool isPrime(int num){
    if(num <= 1){
        return false;
    }
    bool flag = true;
    for(int i = 2; i <= num / 2; i++){
        if(num % i == 0){
            flag = false;
            break;
        }
    }
    return flag ;
}
void deleteSmallestPrime(int heap[], int* size){
    int smallestPrimeIndex = -1;
    for(int i = 0; i < *size; i++){
        if(smallestPrimeIndex == -1 || heap[i] < heap[smallestPrimeIndex]){
            smallestPrimeIndex = i;
        }
    }
    if(smallestPrimeIndex != -1){
        swap(heap[smallestPrimeIndex], heap[*size - 1]);
        (*size)--;
        minHeapify(heap, *size, smallestPrimeIndex);
    }
}
int main() {
    int n;
    cin >> n;

    int heap[n];
    int size = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, &size, value);
    }

    cout << "Min Heap: ";
    displayMinHeap(heap, size);

    deleteSmallestPrime(heap, &size);

    cout << "Updated Min Heap: ";
    displayMinHeap(heap, size);

    return 0;
}