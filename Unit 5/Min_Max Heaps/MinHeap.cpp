/* Aiden is working on organizing his collection of unique integers, which represent the number of books   
   he has in different categories. He wants to create a min heap out of these integers so that he can 
   quickly access the category with the smallest number of books. Additionally, Aiden is curious about 
   the sum of all even and odd numbers in his collection.

   Write a program that builds a min heap from Aiden's collection of numbers, displays the min heap, 
   and calculates the sum of even and odd numbers separately. */

#include <iostream>
using namespace std;

void minHeapify(int heap[], int size, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // If left child is smaller than root
    if(left < size && heap[left] < heap[smallest]){
        smallest = left;
    }
    // If right child is smaller than smallest so far
    if(right < size && heap[right] < heap[smallest]){
        smallest = right;
    }
    // If smallest is not root, swap and continue heapifying
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        minHeapify(heap, size, smallest);
    }
}

void displayMinHeap(int heap[], int size) {
    cout << "Min Heap: ";
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int parent(int i){ return (i - 1) / 2; }

void insert(int heap[], int &size, int val, int &evenSum, int &oddSum){
    
    heap[size] = val;
    size++;

    if(val % 2 == 0){ evenSum += val; }
    else{ oddSum += val; }

    int index = size - 1;
    while(index != 0 && heap[parent(index)] > heap[index]){
        swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}
int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int heap[n];
    int size = 0;
    int sumEven = 0, sumOdd = 0;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(heap, size, value, sumEven, sumOdd);
    }
    
    
    displayMinHeap(heap, size);

    cout << "Sum of even elements: " << sumEven << endl;
    cout << "Sum of odd elements: " << sumOdd << endl;

    return 0;
}