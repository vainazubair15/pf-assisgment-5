#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure for Vehicle Registration
struct Vehicle {
    int vehicleID;
    string ownerName;
    string vehicleType;
    string licensePlate;
    string registrationDate;
};

// Structure for Traffic Violation
struct Violation {
    int violationID;
    int vehicleID;
    string violationType;
    string dateTime;
    double fineAmount;
    //arshia pgl
};

// Arrays for storing data
Vehicle vehicles[100];
Violation violations[100];
int vehicleCount = 0;
int violationCount = 0;

// Function Prototypes
void manageTrafficLights();
void registerVehicle();
void trackVehicles();
void recordViolation();
void searchViolation();
void generateReports();
void adminDashboard();
void emergencyVehicleAssistance();

// Main Function
int main() {
    adminDashboard();
    return 0;
}

// Admin Dashboard
void adminDashboard() {
    int choice;
    while (true) {
        cout << "\n--- Admin Dashboard ---\n";
        cout << "1. Manage Traffic Lights\n";
        cout << "2. Register and Track Vehicles\n";
        cout << "3. Record Traffic Violation\n";
        cout << "4. Search Violations\n";
        cout << "5. Generate Reports\n";
        cout << "6. Emergency Vehicle Assistance\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                manageTrafficLights();
                break;
            case 2:
                registerVehicle();
                break;
            case 3:
                recordViolation();
                break;
            case 4:
                searchViolation();
                break;
            case 5:
                generateReports();
                break;
            case 6:
                emergencyVehicleAssistance();
                break;
            case 7:
                cout << "Exiting... Goodbye!\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Traffic Light Management
void manageTrafficLights() {
    string lights[] = {"RED", "GREEN", "YELLOW"};
    int numIntersections = 3;

    cout << "\n--- Traffic Light Management ---\n";
    for (int i = 0; i < numIntersections; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Intersection " << i + 1 << ": " << lights[j] << endl;
        }
    }
}

// Vehicle Registration
void registerVehicle() {
    Vehicle v;
    cout << "\nEnter Vehicle ID: ";
    cin >> v.vehicleID;
    cin.ignore();
    cout << "Enter Owner Name: ";
    getline(cin, v.ownerName);
    cout << "Enter Vehicle Type: ";
    getline(cin, v.vehicleType);
    cout << "Enter License Plate: ";
    getline(cin, v.licensePlate);
    cout << "Enter Registration Date: ";
    getline(cin, v.registrationDate);

    vehicles[vehicleCount++] = v;

    ofstream outFile("vehicles.txt", ios::app);
    outFile << v.vehicleID << "," << v.ownerName << "," << v.vehicleType << ","
            << v.licensePlate << "," << v.registrationDate << "\n";
    outFile.close();

    cout << "Vehicle registered successfully!\n";
}

// Record Traffic Violation
void recordViolation() {
    Violation v;
    cout << "\nEnter Violation ID: ";
    cin >> v.violationID;
    cout << "Enter Vehicle ID: ";
    cin >> v.vehicleID;
    cin.ignore();
    cout << "Enter Violation Type: ";
    getline(cin, v.violationType);
    cout << "Enter Date and Time: ";
    getline(cin, v.dateTime);
    cout << "Enter Fine Amount: ";
    cin >> v.fineAmount;

    violations[violationCount++] = v;

    ofstream outFile("violations.txt", ios::app);
    outFile << v.violationID << "," << v.vehicleID << "," << v.violationType << ","
            << v.dateTime << "," << v.fineAmount << "\n";
    outFile.close();

    cout << "Violation recorded successfully!\n";
}

// Search Violations
void searchViolation() {
    int searchID;
    cout << "\nEnter Vehicle ID to search violations: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < violationCount; i++) {
        if (violations[i].vehicleID == searchID) {
            cout << "\nViolation ID: " << violations[i].violationID
                 << "\nVehicle ID: " << violations[i].vehicleID
                 << "\nViolation Type: " << violations[i].violationType
                 << "\nDate and Time: " << violations[i].dateTime
                 << "\nFine Amount: " << violations[i].fineAmount << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No violations found for Vehicle ID " << searchID << ".\n";
    }
}

// Generate Reports
void generateReports() {
    cout << "\n--- Traffic Reports ---\n";
    cout << "Total Vehicles Registered: " << vehicleCount << "\n";
    cout << "Total Violations Recorded: " << violationCount << "\n";

    int totalFines = 0;
    for (int i = 0; i < violationCount; i++) {
        totalFines += violations[i].fineAmount;
    }
    cout << "Total Fines Collected: $" << totalFines << "\n";
}

// Emergency Vehicle Assistance
void emergencyVehicleAssistance() {
    int location, destination;
    cout << "\nEnter Emergency Vehicle Location: ";
    cin >> location;
    cout << "Enter Destination: ";
    cin >> destination;

    cout << "Traffic lights along the route are set to GREEN.\n";
}

