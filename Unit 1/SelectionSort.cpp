// Students are arranged in a random order. Using Selection Sort, 
// sort the students according to their heights. Print after each iteration
// Selection sort takes a T.C -> O(N*N)
#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &v, int n){
    // It'll find the smallest element in each iteration and sorts ascending wise
    for(int i = 0; i < n - 1; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[mini])  mini = j;
        }
        swap(v[i], v[mini]);
        cout << "Height order of students after iteration " << (i+1) << ": ";
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}
int main(){
    int size;
    cout << "Enter the number of students: ";
    cin >> size;
    vector<int> v1(size);
    cout << "Enter the height of students seperated by spaces: ";
    for(int i = 0; i < size; i++){
        cin >> v1[i];
    }
    cout << "Student's height order before sorting: ";
    for(int i = 0; i < size; i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    selectionSort(v1, size);
    cout << "After final comparison of all students, the height order becomes: ";
    for(int i = 0; i < size; i++){
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}