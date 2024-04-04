#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <iomanip>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    // Perform insertion sort
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto stop = chrono::high_resolution_clock::now();
    auto duration_insertion = chrono::duration_cast<chrono::milliseconds>(stop - start).count();

    /*// Print the sorted array
    cout << "Sorted array (" << filename << "): ";
    print_arr(arr);*/

    // Print the time taken for insertion sort
    cout << "Time for the Merge sort on " << filename << " is: " << duration_insertion << " milliseconds" << endl;
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





// C++ code to print BFS traversal from a given
// source vertex
/*
#include <bits/stdc++.h>
using namespace std;

class Graph {

	// No. of vertices
	int V;

	// Pointer to an array containing adjacency lists
	vector<list<int>> adj;
    //Graph(V,d) 

public:
	// Constructor
	Graph(int V);

	// Function to add an edge to graph
	void addEdge(int v, int w);

	// Prints BFS traversal from a given source s
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
	// Add w to v’s list.
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	vector<bool> visited;
    vector<string>color;
    vector<int>p;
    
	visited.resize(V, false);

	// Create a queue for BFS
	list<int> queue;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	while (!queue.empty()) {

		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		// Get all adjacent vertices of the dequeued
		// vertex s.
		// If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (auto adjacent : adj[s]) {
			if (!visited[adjacent]) {
				visited[adjacent] = true;
				queue.push_back(adjacent);
			}
		}
	}
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
*/

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* next;
    string color;  // "white", "gray", or "black"
    int distance;
    Node* predecessor;
};

class Graph {
public:
    Node** head;
    int V;

    Graph(int V) {
        this->V = V;
        head = new Node*[V];
        for (int i = 0; i < V; i++) {
            head[i] = nullptr;
        }
    }
    void BFS(int s) {
        queue<int> q;
        q.push(s);

        // Initialize colors, distances, and predecessors
        for (int i = 0; i < V; i++) {
            head[i]->color = "white";
            head[i]->distance = -1;  // Infinite distance initially
            head[i]->predecessor = nullptr;
        }

        head[s]->color = "gray";
        head[s]->distance = 0; 
        // head[i]->predecessor = nullptr;
        q.push(s);
         // Distance of source from itself is 0

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            Node* temp = head[u];
            while (temp != nullptr) {
                int v = temp->data;
                if (head[v]->color == "white") {
                    head[v]->color = "gray";
                    head[v]->distance = head[u]->distance + 1;
                    head[v]->predecessor = head[u];
                    q.push(v);
                }
                temp = temp->next;
            }

            head[u]->color = "black";  // Fully processed
        }
    }
};