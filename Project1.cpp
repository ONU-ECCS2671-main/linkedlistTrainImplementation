/*
Course: ECCS 2671 -- Data Structures and Algorithms 1
Group Members: ______ and _______

Use this code template to submit Project 1.

Implement all of the member functions that have not been implemented based on the functionality in the handout

You are NOT allowed to modify the TrainCompositionManager class, only complete the class implementation.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrainCompositionManager {

private:
    struct CarNode {
        int carNumber;
        string carName;
        string carType;
        string manufacturerName;
        double weightTons;
        CarNode* next;
        CarNode* prev;

        // Default constructor for CarNode
        CarNode() { carNumber=1; carName=""; carType=""; manufacturerName=""; weightTons=0.0; next=prev=nullptr; }
        // Parameterized constructor for CarNode
        CarNode(string cName, int cNum, string cType, double wTons, string mName = "", CarNode* nCar = nullptr, CarNode* pCar = nullptr)
        {
            carNumber = cNum;
            carName = cName;
            carType = cType;
            weightTons = wTons;
            manufacturerName = mName;
            next = nCar;
            prev = pCar;
        }
    };

    int numCars;
    CarNode* head;
    CarNode* tail;

    // A private helper function for Student 1
    CarNode* getCarNode(const string carName);

    // A private helper function for Student 2
    CarNode* getCarNode(const int carNumber);

public:
    // Default constructor
    TrainCompositionManager() { numCars = 0; head = tail = nullptr; }
    
    // Destructor to be implemented by Student 2
    ~TrainCompositionManager();

    // Student 1 Member Functions
    void addCar(const string addedCarName, const string carType, const double weightTons);
    void addCar(const string addedCarName, const int carNumber, const string carType, const double weightTons);
    void deleteCar(const string deletedCarName);
    int getCarNum(const string searchedCarName);
    vector<string> getAllCarNamesByType(const string carType);

    // Student 2 Member Functions
    void addCar(const string addedCarName, const int carNumber, const string carType, const double weightTons, const string manufacturer);
    void deleteLastCar();
    void deleteCar(const int carNumInList);
    string getCarName(const int carNumInList);
    int getNumCars() const { return numCars; }
    int getCarTypeCount(const string carType);
    
    // Overloaded << operator to print the train composition
    friend ostream& operator<<(ostream& outputStream, const TrainCompositionManager& trainList);
};

// ********************************************************************************************
// Implement the following functions here.
// Each student should only complete their assigned functions.
// ********************************************************************************************

// Student 1 Functions:
// Function descriptions are in the project handout.
TrainCompositionManager::CarNode* TrainCompositionManager::getCarNode(const string carName) {
    // Student 1, implement this function
}

void TrainCompositionManager::addCar(const string addedCarName, const string carType, const double weightTons) {
    // Student 1, implement this function
}

void TrainCompositionManager::addCar(const string addedCarName, const int carNumber, const string carType, const double weightTons) {
    // Student 1, implement this function
}

void TrainCompositionManager::deleteCar(const string deletedCarName) {
    // Student 1, implement this function
}

int TrainCompositionManager::getCarNum(const string searchedCarName) {
    // Student 1, implement this function
}

vector<string> TrainCompositionManager::getAllCarNamesByType(const string carType){
    // Student 1, implement this function
}

// Student 2 Functions:
// Function descriptions are in the project handout.
TrainCompositionManager::CarNode* TrainCompositionManager::getCarNode(const int carNumber) {
    // Student 2, implement this function
}

void TrainCompositionManager::addCar(const string addedCarName, const int carNumber, const string carType, const double weightTons, const string manufacturer) {
    // Student 2, implement this function
}

void TrainCompositionManager::deleteLastCar() {
    // Student 2, implement this function
}

void TrainCompositionManager::deleteCar(const int carNumInList) {
    // Student 2, implement this function
}

string TrainCompositionManager::getCarName(const int carNumInList) {
    // Student 2, implement this function
}

int TrainCompositionManager::getCarTypeCount(const string carType){
    // Student 2, implement this function
}
// ********************************************************************************************
// Fully implemented functions (no modification needed)
// ********************************************************************************************
TrainCompositionManager::~TrainCompositionManager() {
    CarNode* deleteNode = head;
    while (deleteNode != nullptr) {
        CarNode* nextNode = deleteNode->next;
        delete deleteNode;
        deleteNode = nextNode;
    }
    head = tail = nullptr;
    numCars = 0;
}

ostream& operator<<(ostream& outputStream, const TrainCompositionManager& trainList) {
    TrainCompositionManager::CarNode* current = trainList.head;
    while (current != nullptr) {
        outputStream << "(" << current->carNumber << ") " << current->carName << ", "<< current->carType <<", ";
        current = current->next;
    }
    outputStream << "End of Train" << endl;
    return outputStream;
}

int main() {
    // You can add your own test cases here to test the functions as you implement them.
    // Comment out or uncomment functions as needed for testing.
    TrainCompositionManager myTrain;
    
    cout << "We start with: " << myTrain.getCarName(1) << endl; // Student 2 member function

    // Test Student 2 Functions
    myTrain.addCar("Red Caboose", 4, "Caboose", 25.0, "Alstom");
    myTrain.addCar("Heavy Cargo Car", 3, "Cargo", 100.0, "Siemens Mobility");

    // Test Student 1 Functions
    myTrain.addCar("The Iron Horse", "Locomotive", 130.0);
    myTrain.addCar("Silver Streak Car", "Passenger", 55.5);
    myTrain.addCar("Grand View Diner", 2, "Dining", 75.2);
    
   // Using Student 1's function to add a car at the head
    myTrain.addCar("Coal Car 1", "Cargo", 80.0); 

    // Using Student 2's function to add a car with a manufacturer
    myTrain.addCar("Observation Car", 3, "Passenger", 60.5, "Kawasaki Heavy Industries");

    // Using Student 1's function to add a car to the middle
    myTrain.addCar("Baggage Car", 5, "Baggage", 45.0);

    // Using Student 2's function to add a car with a manufacturer at the tail
    myTrain.addCar("Reefer Car 1", 100, "Cargo", 110.0, "CRRC Corporation");

    // Using Student 1's function with an invalid weight
    myTrain.addCar("Invalid Weight Car", "Test", 5.0); // Should trigger an error message

    // Using Student 2's function with an invalid weight and a manufacturer
    myTrain.addCar("Another Invalid Car", 2, "Test", 200.0, "Alstom"); // Should trigger an error message

    // Print the train composition
    cout << "The train has " << myTrain.getNumCars() << " cars:" << endl;
    cout << myTrain << endl;
    
    // Demonstrate other functions
    cout << "The car number for 'Grand View Diner' is " << myTrain.getCarNum("Grand View Diner") << endl; // Student 1 member function
    cout << "The car name at position 3 is " << myTrain.getCarName(3) << endl; // Student 2 member function

    cout << "There are " << myTrain.getCarTypeCount("Cargo") << " cargo cars in the train." << endl; // Student 2 member function
    cout << "There are " << myTrain.getCarTypeCount("Passenger") << " passenger cars in the train." << endl; // Student 1 member function

    // Test deletion functions
    cout << "\nDeleting a few cars..." << endl; 
    myTrain.deleteCar("Grand View Diner"); // Student 1 member function
    myTrain.deleteLastCar(); // Student 2 member function
    myTrain.deleteCar(1); // Student 2 member function

    // Print the final train composition
    cout << "The final train has " << myTrain.getNumCars() << " cars:" << endl;
    cout << myTrain << endl;
    return 0;
}