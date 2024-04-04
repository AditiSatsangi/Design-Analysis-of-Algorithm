
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
using namespace std;

void insertion_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int unsorted_element = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > unsorted_element) {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = unsorted_element;
    }
}


void processFile(const string& filename, vector<int>& arr) {
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error reading the input file: " << filename << endl;
        return;
    }
    int number;
    while (inputFile >> number) {
        arr.push_back(number);
    }
    inputFile.close();

    // Perform insertion sort
    auto start = chrono::high_resolution_clock::now();
    insertion_sort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    // Print the time taken for insertion sort
    cout << "Time for the insertion sort on " << filename << " is: " << duration_insertion << " milliseconds" << endl;
}

int main() {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    vector<int> arr4;
    vector<int> arr5;
    vector<int> arr6;

    processFile("f1.txt", arr1);
    processFile("f2.txt", arr2);
    processFile("f3.txt", arr3);
    processFile("f4.txt", arr4);
    processFile("f5.txt", arr5);
    processFile("f6.txt", arr6);

    return 0;
}
