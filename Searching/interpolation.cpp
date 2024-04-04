#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <random>
#include <algorithm>
using namespace std;

int interpolationSearch(const vector<int>& arr, int sn) {
    int low = 0;
    int high = arr.size() - 1;
/*
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target) {
            return pos;  // Return the index if found
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;  // Return -1 if not found
} */

    int s = 0, e = arr.size() - 1, est, pos = -1;

    while (s <= e && sn >= arr[s] && sn <= arr[e]) {
        est = s + ((e - s) / (arr[e] - arr[s])) * (sn - arr[s]);

        if (arr[est] == sn) {
            pos = est;
            break;
        } else if (arr[est] < sn) {
            s = est + 1;
        } else {
            e = est - 1;
        }
    }

    return pos;
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

    // Sort the array
    sort(arr.begin(), arr.end());

    // Use <random> to generate a random index
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, arr.size() - 1);
    int randomIndex = distribution(gen);

    // Assign the element at the randomly selected index as the target
    int target = arr[randomIndex];

    auto start = chrono::high_resolution_clock::now();
    int result = interpolationSearch(arr, target);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found" << endl;
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration_search = chrono::duration_cast<chrono::nanoseconds>(stop - start).count();

    // Print the time taken for the linear search
    cout << "Time for Interpolation search on " << filename << " is: " << duration_search << " nanoseconds" << endl;
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