/* Your task is to create a basic airline flight reservation system. This system allows users to manage 
   available flights, book tickets, and view information about upcoming flights.
   The program employs a priority queue to efficiently manage the flights based on their departure times 
   and ticket prices. Each flight is represented by its flight number, departure time, and ticket price. 
   A lower departure time indicates the highest priority. */

#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Flight{
public:
    string flightNum;
    int depTime;
    double price;
    
    Flight() {} // Default constructor is essential for priority Queue

    Flight(string fN, int dT, double p){
        this->flightNum = fN;
        this->depTime = dT;
        this->price = p;
    }
    
    bool operator<(const Flight &other) const{
        return depTime > other.depTime;
    }
};

int main(){
    priority_queue<Flight> fq;
    int choice;
    while(true){
        cin >> choice;
        switch(choice){
            case 1:{
                string flightNum;
                int depTime;
                double price;
                cin.ignore();
                getline(cin, flightNum);
                cin >> depTime;
                cin >> price;
                fq.push(Flight(flightNum, depTime, price));
                cout << "Flight added to the Queue." << endl;
                break;
            }
            case 2:
                if(!fq.empty()){
                    cout << "Booked ticket for flight: " << fq.top().flightNum << endl;
                    fq.pop();
                } else{
                    cout << "No flights available." << endl;
                }
                break;
            case 3:
                if(!fq.empty()){
                    cout << "Next available flight: " << fq.top().flightNum << endl;
                } else{
                    cout << "No flights available." << endl;
                }
                break;
            case 4:
                cout << "Exiting the application..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    return 0;
}