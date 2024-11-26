#include <iostream>
using namespace std;
int divisionMethod(int key, int tableSize){
    return key % tableSize;
}
void readKeys(int keys[], int numKeys){
    for(int i = 0; i < numKeys; i++){
        cin >> keys[i];
    }
}
void initializeHashTable(int hashTable[], int tableSize){
    for(int i = 0; i < tableSize; i++){
        hashTable[i] = -1;
    }
}
void insertKeys(int hashTable[], int tableSize, int keys[], int numKeys){
    for(int i = 0; i < numKeys; i++){
        int key = keys[i];
        int hashIndex = divisionMethod(key, tableSize);
        while(hashIndex < tableSize){
            if(hashTable[hashIndex] == -1){
                hashTable[hashIndex] = key;
                break;
            } else{
                hashIndex = (hashIndex + 1) % tableSize;
            }
        }
    }
}
void printHashTable(int hashTable[], int tableSize){
    for(int i = 0;i < tableSize; i++){
        if(hashTable[i] != -1){
            cout << hashTable[i] << " ";
        }
    }
    cout << endl;
}
int main(){
    const int tableSize = 10;
    int numKeys;
    cin >> numKeys;
    int keys[numKeys];
    readKeys(keys, numKeys);
    int hashTable[tableSize];
    initializeHashTable(hashTable, tableSize);
    insertKeys(hashTable, tableSize, keys, numKeys);
    printHashTable(hashTable, tableSize);
    return 0;
}