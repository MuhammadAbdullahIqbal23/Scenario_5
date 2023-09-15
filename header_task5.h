//Muhammad_Abdullah_Abdullah_Iqbal_22i2504
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>


using namespace std;

template <typename T>
struct EmployeeData {
    T name;
    T employeeID;
    double salary;
    T dateOfJoining;
    T designation;

    EmployeeData(const T& name, const T& employeeID, double salary, const string& dateOfJoining, const T& designation)
        : name(name), employeeID(employeeID), salary(salary), dateOfJoining(dateOfJoining), designation(designation)
    {
    }

    EmployeeData() = default;
};
template<typename T>
void InsertionSort(int maxEmployees, EmployeeData<T> employees[]) {
    cout << "This is done by insertion sort: \n";
    EmployeeData<T> temp; // for swap

    int comparisons = 0; // Counter for comparisons
    int swaps = 0;      // Counter for swaps

    auto start_time = chrono::high_resolution_clock::now(); // Start measuring time

    for (int i = 1; i < maxEmployees; i++) {
        temp = employees[i]; // Current element to be inserted
        int j = i - 1;

        // Compare elements and count comparisons
        comparisons++;
        while (j >= 0 && employees[j].dateOfJoining > temp.dateOfJoining) {
            employees[j + 1] = employees[j];
            j--;

            swaps++; // Count swaps
        }

        employees[j + 1] = temp; // Insert the current element into the correct position
    }

    auto end_time = chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    for (int i = 0; i < maxEmployees; i++) {
        cout << employees[i].name <<": " << employees[i].dateOfJoining << endl;
    }

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

template<class T>
void SelectionSort(int maxEmployees, EmployeeData<T> employees[]) {
    cout << "This is done by selection sort: \n";

    EmployeeData<T> temp; // for swap
    int max_index; // index of max value

    int comparisons = 0; // Counter for comparisons
    int swaps = 0;      // Counter for swaps

    auto start_time = chrono::high_resolution_clock::now(); // Start measuring time

    for (int rightmost = maxEmployees - 1; rightmost > 0; rightmost--) {
        max_index = 0;
        for (int current = 1; current <= rightmost; current++) {
            comparisons++; // Increment comparison count
            if (employees[current].dateOfJoining > employees[max_index].dateOfJoining) {
                max_index = current;
            }
        }

        if (employees[max_index].dateOfJoining > employees[rightmost].dateOfJoining) {
            temp = employees[max_index]; // swap
            employees[max_index] = employees[rightmost];
            employees[rightmost] = temp;
            swaps++; // Increment swap count
        }
    }

    auto end_time = chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Employees sorted according to their dateOfJoining in ascending order:" << endl;
    for (int i = 0; i < maxEmployees; i++) {
        cout << i << ":" << employees[i].name << endl;
    }

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}

template<typename T>
void BubbleSort(int maxEmployees, EmployeeData<T> employees[]) {
    cout << "This is done by bubble sorting:" << endl;

    int comparisons = 0; // Counter for comparisons
    int swaps = 0;      // Counter for swaps

    auto start_time = chrono::high_resolution_clock::now(); // Start measuring time

    for (int pass = 1; pass < maxEmployees; pass++) {
        for (int i = 0; i < maxEmployees - pass; i++) {
            comparisons++; // Increment comparison count
            if (employees[i].dateOfJoining > employees[i + 1].dateOfJoining) {
                EmployeeData<T> tmp = employees[i];
                employees[i] = employees[i + 1];
                employees[i + 1] = tmp;
                swaps++; // Increment swap count
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now(); // Stop measuring time
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "Employees sorted according to their dateOfJoining in ascending order:" << endl;
    for (int i = 0; i < maxEmployees; i++) {
        cout << i << ":" << employees[i].name << endl;
    }

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
}


template <typename T>
int ReadEmployeeData(const char* filename, EmployeeData<T> employees[], int maxEmployees) {
    ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int employeeCount = 0;
    int ShortestTenureIndex = 0;

    for (int i = 0; i < maxEmployees; ++i) {
        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].name);

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].employeeID);

        inputFile.ignore(100, '$');
        inputFile >> employees[i].salary;

        inputFile.ignore(100, ':');
        inputFile >> employees[i].dateOfJoining;

        inputFile.ignore(100, ':');
        getline(inputFile, employees[i].designation);
        inputFile.ignore(2, '\n');

        employeeCount++;


    }

    inputFile.close();


    if (employeeCount > 0) {
        int value = -1;

       
            cout << endl << "Press the following: " << endl;
            cout << "1) Enter 1 for BubbleSort\n2) Enter 2 for SelectionSort\n3) Enter 3 for InsertionSort\n4) Enter 0 to exit\nValue: ";

            // Receive user input
            cin >> value;
            cout << endl;


            if (value == 1)
                BubbleSort(maxEmployees, employees);
            else if (value == 2)
                SelectionSort(maxEmployees, employees);
            else if (value == 3)
                InsertionSort(maxEmployees, employees);

        
    }
    else {
        cout << "No employee data found." << endl;
    }

    return 0;
}

