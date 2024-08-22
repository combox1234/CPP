#include <iostream>
#include <string>
using namespace std;

class employee {
public:
    int id;
    string name;
    double salary;
    void get() {
        cout << "Enter employee id: ";
        cin >> id;
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee salary: ";
        cin >> salary;
    }
    void show() {
        cout << "ID: " << id << "\tName: " << name << "\tSalary: " << salary << endl;
    }
};

// Quick sort function
void quickSort(employee arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Partition function
int partition(employee arr[], int low, int high) {
    string pivot = arr[high].name;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].name <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Swap function
void swap(employee& a, employee& b) {
    employee temp = a;
    a = b;
    b = temp;
}

int main() {
    int x;
    cout << "Enter total number of employees: ";
    cin >> x;
    employee E[x];
    int choice;
    do {
        cout << "Enter your choice:" << endl << "1.Enter Information " << endl << "2.Display" << endl << "3.Sort" << endl << "4.Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                for (int i = 0; i < x; i++) {
                    E[i].get();
                }
                break;
            case 2:
                for (int i = 0; i < x; i++) {
                    E[i].show();
                }
                break;
            case 3:
                quickSort(E, 0, x - 1);
                cout << "Sorted by name:" << endl;
                for (int i = 0; i < x; i++) {
                    E[i].show();
                }
                break;
            case 4:
                cout << "Exit";
                break;
            default:
                cout << "Enter valid choice";
                break;
        }
    } while (choice != 4);
    return 0;
}
