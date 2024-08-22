#include <iostream>
using namespace std;

class Student {
    int rollno;
    double cgpa; 
    string name;
public:
    void getData() {
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }
    void display() {
        cout << "Roll number: " << rollno << "\tName: " << name << "\tCGPA: " << cgpa << endl;
    }
    float getcgpa() {
        return cgpa;
    }
    void setStudent(Student s) {
        rollno = s.rollno;
        name = s.name;
        cgpa = s.cgpa;
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    Student students[n];
    int choice;
    do {
        cout << "1. Enter Data\n2. Display Data\n3. Sort Data\n4. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    students[i].getData();
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;
            case 3:
                for (int i = 1; i < n; i++) {
                    Student key=students[i];
                    int j=i-1;
                    while (j>=0 && students[j].getCgpa()>key.getCgpa()) {
                        students[j+1].setStudent(students[j]);
                        j--;
                    }
                    students[j + 1].setStudent(key);
                }
                cout<<"Sorted data:"<<endl;
                for (int i = 0; i < n; i++) {
                    students[i].display();
                }
                break;
            case 4:
                choice = 4;
                break;
            default:
                cout<<"invalid choice!?!?!?."<<endl;
        }
    } while (choice != 4);
    return 0;
}
