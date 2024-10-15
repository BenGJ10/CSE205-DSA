/* You are working for an e-commerce company that wants to analyze customer purchase data. 
   The company is interested in understanding the frequency of items purchased by customers and then 
   displaying these items sorted by their purchase frequency. If two items have the same frequency, 
   the item with the higher value should come first in the output.

   Given a list of purchased items, your task is to count the frequency of each item and then sort these 
   items based on their frequency in descending order using the merge sort algorithm. If two items have
   the same frequency, sort them in descending order based on their values. */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void merge(vector<pair<int, int> > &arr, int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<pair<int, int> > ans;
    while(left <= mid && right <= high){
        if(arr[left].second > arr[right].second || 
            (arr[left].second == arr[right].second && arr[left].first > arr[right].first))
        {
            ans.push_back(arr[left]);
            left++;
        } else{
            ans.push_back(arr[right]);
            right++;
        }   
    }
    while(left <= mid){
        ans.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        ans.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++){
        arr[i] = ans[i - low];
    }
}
void mergeSort(vector<pair<int, int> > &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main(){
    int num;
    cin >> num;
    vector<int> items(num);
    for(int i = 0; i < num; i++){
        cin >> items[i];
    }

    // Counting frequencies using a hash map
    unordered_map<int, int> freq;
    for(int item : items){
        freq[item]++;
    }

    // Storing the items with their frequencies in a vector of pairs
    vector<pair<int, int> > itemFreq;
    for(auto &entry : freq){
        itemFreq.push_back({entry.first, entry.second});
    }

    // Sorting the items by frequency and value using merge sort
    mergeSort(itemFreq, 0, itemFreq.size() - 1);
    
    for(auto &p : itemFreq){
        for(int i = 0; i < p.second; i++){
            cout << p.first << " ";
        }
    }
    cout << endl;
    return 0;
}