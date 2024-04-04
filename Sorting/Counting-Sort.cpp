#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<iomanip>
#include<random>

using namespace std;

void countingSort(vector<int> &a){
 int max_Element=  *max_element(a.begin(),a.end());
 vector<int>count(max_Element,0);
 vector<int>output(a.size());

 for(int num: a){
    count[num]++;
 }
 for(int i=1;i<=max_Element;++i){
    count[i]= count[i-1]+1;
 }

 for(int i= a.size();i>=0;--i){
    output[count[a[i]]]= a[i];
    count[a[i]]--;
 }

 for(size_t i=0;i<a.size(); ++i){
     a[i]= output[i];
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
    countingSort(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start).count();
    cout << "Time for the Counting sort on " << filename << " is: " << duration_insertion << " milliseconds" << endl;
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