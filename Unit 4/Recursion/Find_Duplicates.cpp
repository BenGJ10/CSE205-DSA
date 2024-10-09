/* You work in a large warehouse where products are numbered from 0 to N-1. Your task is to 
   identify any products that appear twice in the inventory list and report them in ascending order. 
   This helps ensure accurate inventory management. */
   
#include <iostream>
#include <vector>
using namespace std;

void findDuplicates(int arr[], int n, int index, vector<int>& duplicates) {
    // Base case
    if (index >= n - 1) {
        return;
    }
    if (arr[index] == arr[index + 1]) {
        // Add it to the duplicates list only if it's not already added
        if (duplicates.empty() || duplicates.back() != arr[index]) {
            duplicates.push_back(arr[index]);
        }
    }
    findDuplicates(arr, n, index + 1, duplicates);
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> duplicates;
    findDuplicates(arr, size, 0, duplicates);
    
    if (duplicates.empty()) {
        cout << "-1" << endl;
    } else {
        for (int i = 0; i < duplicates.size(); i++) {
            cout << duplicates[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
