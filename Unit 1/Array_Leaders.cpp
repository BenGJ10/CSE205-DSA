/* An element of the array is considered a leader if it is greater than all the elements 
   on its right side or if it is equal to the maximum element on its right side.  
   Your task is to find all the leaders in the array. */
#include <iostream>
#include <vector>
using namespace std;
vector<int> findLeaders(vector<int> &v, int n){
        vector<int> ans;
        int leader = v[n - 1];
        ans.push_back(-1);
        for(int i = n - 2; i >= 0; i--){
            if(v[i] >= leader){
                ans.push_back(v[i]);
                leader = v[i];
            }
        }
        return ans;
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
    vector<int> ans = findLeaders(v1, size);
    for(int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}