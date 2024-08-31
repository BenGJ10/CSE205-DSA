// Given an array, find the second largest element in the array.
#include <iostream>
#include <vector>
using namespace std;
int secondLargest(vector<int> &v, int n){
    int largest = v[0];
    int s_largest = -1;
    for(int i = 0; i < n; i++){
        if(v[i] > largest){
            s_largest = largest;
            largest = v[i];
        }
        if(largest > s_largest && v[i] < largest && v[i] > s_largest){
            s_largest = v[i];
        }
    }
    return s_largest;
}
int main(){
    int size;
    cout << "Enter the size: ";
    cin >> size;
    vector<int> v1(size);
    cout << "Enter the elements: ";
    for(int i = 0; i < size; i++){
        cin >> v1[i];
    }
    int s_largest = secondLargest(v1, size);
    cout << "Second Largest element is: " << s_largest << endl;
    return 0;
}