/* Emma is a mathematics enthusiast who wants to analyze prime numbers for her research. She collects 
  several integers and aims to create a max heap that only includes the prime numbers from her collection.
  
  After inserting the prime numbers into the max heap, she wants to visualize the max heap structure to 
  understand the hierarchy of these numbers. A prime number is a natural number greater than one that
  has no positive divisors other than one and itself. */

#include <iostream>
using namespace std;

void maxHeapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        maxHeapify(arr, size, largest);
    }
}

int parent(int i ){
    return (i - 1) / 2;
}
void insertIntoMaxHeap(int arr[], int *n, int value) {
    arr[*n] = value;
    int index = *n;
    (*n)++;
    
    while(index != 0 && arr[parent(index)] < arr[index]){
        swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}

bool isPrime(int num) {
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
    return flag;
}

void printMaxHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int elements;
    cin >> elements;
    int arr[elements];
    int size = 0;

    for (int i = 0; i < elements; i++) {
        int value;
        cin >> value;

        if (isPrime(value)) {
            insertIntoMaxHeap(arr, &size, value);
        } else {
            cout << value << " is not a prime number" << endl;
        }
    }
    maxHeapify(arr, size, 0);
    cout << "Max Heap: ";
    printMaxHeap(arr, size);

    return 0;
}