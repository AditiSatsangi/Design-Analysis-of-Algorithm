#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

void selectionsort(vector<int> &arr){
    int n = arr.size();
    int minindex;
    for(int i=0; i<n; i++){
       minindex = i;
       for(int j = i+1 ; j<n ; j++){
        if(arr[j] > arr[minindex]){
            swap (arr[j], arr[minindex]);
        }
       }
    }
}

// Function to read from a file, perform selection sort, and measure time
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

    // Perform selection sort
    auto start = chrono::high_resolution_clock::now();
    selectionsort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_selection = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    // Print the time taken for selection sort
    cout << "Time for the selection sort on " << filename << " is: " << duration_selection << " milliseconds" << endl;
}

int main(){

vector<int> arr1;
vector<int> arr2;
vector<int> arr3;
vector<int> arr4;
vector<int> arr5;
vector<int> arr6;

ifstream inputFile1("f1.txt");
ifstream inputFile2("f2.txt");
ifstream inputFile3("f3.txt");
ifstream inputFile4("f4.txt");
ifstream inputFile5("f5.txt");
ifstream inputFile6("f6.txt");


    processFile("f1.txt", arr1);
    processFile("f2.txt", arr2);
    processFile("f3.txt", arr3);
    processFile("f4.txt", arr4);
    processFile("f5.txt", arr5);
    processFile("f6.txt", arr6);

}