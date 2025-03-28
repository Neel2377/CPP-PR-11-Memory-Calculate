#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Template class Memory to store student IDs and names
template <typename T>
class Memory
{
public:
    vector<T> sid;        // Vector to store student IDs
    vector<string> sname; // Vector to store student names

    Memory() {}  // Constructor
    ~Memory() {} // Destructor
};

// Template class Student inheriting from Memory
template <typename T>
class Student : public Memory<T>
{

public:
    // Function to add student details
    void addStudent()
    {
        int numstudents;
        cout << "Enter number of students: ";
        cin >> numstudents;

        for (int i = 0; i < numstudents; i++)
        {
            T id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin >> name;

            // Store student details in the vectors
            this->sid.push_back(id);
            this->sname.push_back(name);
        }
    }

    // Function to display all students
    void displayStudent()
    {
        cout << endl;
        cout << "===Student List===" << endl;
        for (size_t i = 0; i < this->sid.size(); i++)
        {
            cout << "Student ID: " << this->sid[i] << endl;
            cout << "Student Name: " << this->sname[i] << endl;
        }
    }

    // Function to delete a student by ID
    void deleteStudent()
    {
        T id;
        cout << "Enter Student ID to delete: ";
        cin >> id;

        for (size_t i = 0; i < this->sid.size(); i++)
        {
            if (this->sid[i] == id)
            {
                this->sid.erase(this->sid.begin() + i);
                this->sname.erase(this->sname.begin() + i);
                cout << "Student deleted successfully." << endl;
            }
        }
    }

    // Function to search for a student by ID
    void searchStudent()
    {
        T id;
        cout << "Enter Student ID to search: ";
        cin >> id;

        for (size_t i = 0; i < this->sid.size(); i++)
        {
            if (this->sid[i] == id)
            {
                cout << "Student ID: " << this->sid[i] << endl;
                cout << "Student Name: " << this->sname[i] << endl;
            }
            else
            {
                cout << "Student not found." << endl;
            }
        }
    }
};

int main()
{
    int choice;
    Student<int> s; // Creating an instance of Student with int as ID type

    do
    {
        // Display menu
        cout << "===============================" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        // Perform action based on user choice
        switch (choice)
        {
        case 1:
            s.addStudent();
            break;
        case 2:
            s.displayStudent();
            break;
        case 3:
            s.deleteStudent();
            break;
        case 4:
            s.searchStudent();
            break;
        case 0:
            cout << "Exit the code......" << endl;
            break;
        default:
            cout << "Invalid Choice. Please try again." << endl;
        }
    } while (choice != 0); // Repeat until the user chooses to exit

    return 0;
}