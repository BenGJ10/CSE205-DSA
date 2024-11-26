#include <iostream>
using namespace std;

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
int midSquareHash(int key, int tableSize, int r){
    int squared = key * key;
    int midVal = (squared / 10) % 10;
    int hashIndex = midVal % tableSize;
    return hashIndex;
}
void insertKeys(int hashTable[], int tableSize, int key){
    int hashIndex = midSquareHash(key, tableSize, 1);
    while(hashTable[hashIndex] != -1){
        hashIndex = (hashIndex + 1) % tableSize;
    }
    hashTable[hashIndex] = key;
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
    const int tableSize = 100;
    int numKeys;
    cin >> numKeys;
    int keys[numKeys];
    readKeys(keys, numKeys);
    int hashTable[tableSize];
    initializeHashTable(hashTable, tableSize);
    for(int i = 0; i < numKeys; i++){
        insertKeys(hashTable, tableSize, keys[i]);
    }
    printHashTable(hashTable, tableSize);
    return 0;
}