#include "main.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    ArrayList<string> list;
    int choice;

    do{
        cout << "\t ArrayList Menu" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Get element" << endl;
        cout << "3. Set element" << endl;
        cout << "4. Remove element" << endl;
        cout << "5. Print list" << endl;
        cout << "6. Get size" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            choice = -1;
            continue;
        }

        switch (choice) {
            case 1: {
                int idx;
                string value;
                cout << "Enter index to add at (0 to " << list.size() << "): ";
                cin >> idx;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number.\n";
                    break;
                }
                cout << "Enter value: ";
                cin.ignore();
                getline(cin, value);
                if (idx >= 0 && idx <= list.size()) {
                    list.add(idx, value);
                    cout << "Added.\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 2: {
                int idx;
                cout << "Enter index to get (0 to " << list.size() - 1 << "): ";
                cin >> idx;
                if (idx >= 0 && idx < list.size()) {
                    cout << "Element at " << idx << ": " << list.get(idx) << "\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 3: {
                int idx;
                string value;
                cout << "Enter index to set (0 to " << list.size() - 1 << "): ";
                cin >> idx;
                cout << "Enter new value: ";
                cin.ignore();
                getline(cin, value);
                if (idx >= 0 && idx < list.size()) {
                    list.set(idx, value);
                    cout << "Set.\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 4: {
                int idx;
                cout << "Enter index to remove (0 to " << list.size() - 1 << "): ";
                cin >> idx;
                if (idx >= 0 && idx < list.size()) {
                    list.remove(idx);
                    cout << "Removed.\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 5:
                cout << "List: ";
                list.print();
                break;
            case 6:
                cout << "Size: " << list.size() << "\n";
                break;
            case 0:
                cout << "Exiting.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}