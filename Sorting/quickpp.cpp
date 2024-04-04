#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
#include<iomanip>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        } 
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void print_arr(const vector<int>& a) {
    for (int num : a) {
        cout << num << " ";
    }
    cout << "\n";
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

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

    /*// Print the sorted array
    cout << "Sorted array (" << filename << "): ";
    print_arr(arr);*/

    // Print the time taken for insertion sort
    cout << "Time for the Quick sort on " << filename << " is: " << duration_insertion << " milliseconds" << endl;
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