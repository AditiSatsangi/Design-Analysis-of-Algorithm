#include<iostream>
#include<vector>
#include<chrono>
#include<fstream>
#include<iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        vector<int> output(arr.size());
        vector<int> count(10, 0);

        for (int i = 0; i < arr.size(); ++i) {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; ++i) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (size_t i = 0; i < arr.size(); ++i) {
            arr[i] = output[i];
        }
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
    radixSort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

    /*// Print the sorted array
    cout << "Sorted array (" << filename << "): ";
    print_arr(arr);*/

    // Print the time taken for insertion sort
    cout << "Time for the Radix sort on " << filename << " is: " << duration_insertion << " milliseconds" << endl;
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