/*  During an archaeological expedition, a team discovers the "Disk of Light," an artefact consisting of 
    concentric rings with unique symbols. To unlock its powers, they must perform "Tower of Hanoi" ritual.

    In this ritual:
    There are three pedestals: Source (A), Auxiliary (B), and Illuminated (C).
    Disks are stacked on the Source pedestal, smaller ones on top of larger ones.
    Only one disk can be moved at a time.
    A disk can only be placed on top of a larger disk or an empty pedestal.
    
    Write a program to assist the archaeological team in calculating the total number of times each 
    ring of the Disk of Light is moved during the Tower of Hanoi ritual. */

#include <iostream>
using namespace std;
void towerOfHanoi(int n, char from_rod, char aux_rod, char dest_rod){
    if(n == 0){
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, dest_rod);
    cout << "Move disk " << n << " from " << from_rod << " to " << dest_rod << endl;
    towerOfHanoi(n - 1, aux_rod, dest_rod, from_rod);
}
int main(){
    int disks;
    cout << "Enter the number of disks: ";
    cin >> disks;
    towerOfHanoi(disks, 'A', 'B', 'C');
    return 0;
}