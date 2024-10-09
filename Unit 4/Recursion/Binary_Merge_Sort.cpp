/* Alex is working on a project where binary data is an essential part of the processing. 
   To optimize data handling, Alex needs to sort an array containing only two types of elements: 0s and 1s. 
   Alex decides to implement a merge sort algorithm to efficiently sort this binary data.
   Write a program to assist Alex in implementing the logic of merge sort along with a recursive function 
   to sort an array of binary data in ascending order. */

#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        } else{
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }
    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}
void mergeSort(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
bool isValidBinary(vector<int> &arr){
    for(int num : arr){
        if(num != 0 && num != 1){
            return false;
        }
    }
    return true;
}
int main(){
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i = 0; i < num; i++){
        cin >> arr[i];
    }
    if(!isValidBinary(arr)){
        cout << "Invalid inputs" << endl;
        return 0;
    }
    cout << "Binary array before Merge Sort: ";
    for(int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, num - 1);
    cout << "Binary array after Merge Sort: ";
    for(int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}