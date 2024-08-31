#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function for the menu
void displayIntroMenu() {
    cout << "Hi! Welcome to the ATM Machine!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
}

// Function for the main menu
void displayMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
}

// Main program
int main() {
    unordered_map<string, string> passwords;  // Stores user ID and password
    unordered_map<string, double> balances;   // Stores user ID and balance
    string userId, password;
    char option;
    bool loggedIn = false;
    double amount;

    while (true) {
        // Introduction menu
        displayIntroMenu();
        cout << "For Example > ";
        cin >> option;

        if (option == 'q') {
            cout << "Thank you for using the ATM! Goodbye!" << endl;
            break;  // Quit the program
        } else if (option == 'c') {
            // Create a new account
            cout << "Please enter your user id: ";
            cin >> userId;
            cout << "Please enter your password: ";
            cin >> password;

            if (passwords.find(userId) == passwords.end()) {
                passwords[userId] = password;  // Store password for the user ID
                balances[userId] = 0.0;        // Initialize balance to zero
                cout << "Thank You! Your account has been created!" << endl;
            } else {
                cout << "User ID already exists! Try logging in or use a different user ID." << endl;
            }
        } else if (option == 'l') {
            // Login
            cout << "Please enter your user id: ";
            cin >> userId;
            cout << "Please enter your password: ";
            cin >> password;

            if (passwords.find(userId) != passwords.end() && passwords[userId] == password) {
                loggedIn = true;
                cout << "Access Granted!" << endl;

                // Main menu after loginning in
                while (loggedIn) {
                    displayMainMenu();
                    cout << "For Example > ";
                    cin >> option;

                    if (option == 'd') {
                        // Deposit money
                        cout << "Amount of deposit: $";
                        cin >> amount;
                        balances[userId] += amount;
                        cout << "$" << amount << " deposited to your account!" << endl;
                    } else if (option == 'w') {
                        // Withdraw money
                        cout << "Amount of withdrawal: $";
                        cin >> amount;
                        if (balances[userId] >= amount) {
                            balances[userId] -= amount;
                            cout << "$" << amount << " withdrawn from your account!" << endl;
                        } else {
                            cout << "Insufficient funds!" << endl;
                        }
                    } else if (option == 'r') {
                        // Request balance
                        cout << "Your balance is $" << balances[userId] << "." << endl;
                    } else if (option == 'q') {
                        // Quit the main menu
                        loggedIn = false;
                        cout << "Logged out successfully!" << endl;
                    } else {
                        cout << "Invalid option. Please try again." << endl;
                    }
                }
            } else {
                cout << "*** LOGIN FAILED! ***" << endl;
            }
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}

