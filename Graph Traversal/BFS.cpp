/*
#include <iostream>
#include <queue>
#include <climits>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    string color;
    int distance;
    Node* predecessor;

    Node(int data) : data(data), next(nullptr), color("white"), distance(INT_MAX), predecessor(nullptr) {}
};

class Graph {
public:
    Node** adjacencyList;
    int numVertices;

    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i] = new Node(i);
        }
    }

    // Add an edge between two vertices
    void addEdge(int src, int dest) {
        Node* srcNode = adjacencyList[src];
        Node* newNode = new Node(dest);
        newNode->next = srcNode->next;
        srcNode->next = newNode;
    }

    // Perform BFS traversal from a given source vertex
    void BFS(int src) {
        queue<Node*> q;
        q.emplace(adjacencyList[src]);  // Use emplace instead of push
        adjacencyList[src]->color = "grey";
        adjacencyList[src]->distance = 0;

        while (!q.empty()) {
            Node* u = q.front();
            q.pop();
            cout << u->data << " ";

            for (Node* v = u->next; v != nullptr; v = v->next) {
                if (v->color == "white") {
                    v->color = "grey";
                    v->distance = u->distance + 1;
                    v->predecessor = u;
                    q.emplace(v);  // Use emplace instead of push
                }
            }

            u->color = "black";
        }
    }
};

int main() {
    // Example usage:
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 0);
    graph.addEdge(3, 2);
    graph.addEdge(3, 4);

    cout << "BFS Traversal starting from vertex 2: ";
    graph.BFS(0);

    return 0;
}
*/
#include <iostream>
#include <queue>
#include <climits>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    string color;
    int distance;
    Node* predecessor;

    Node(int data) : data(data), next(nullptr), color("white"), distance(INT_MAX), predecessor(nullptr) {}
};

class Graph {
public:
    Node** adjacencyList;
    int numVertices;

    Graph(int numVertices) : numVertices(numVertices) {
        adjacencyList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i] = new Node(i);
        }
    }

    // Add an edge between two vertices
    void addEdge(int src, int dest) {
        // Adding edge from src to dest
        Node* srcNode = adjacencyList[src];
        Node* newNode = new Node(dest);
        newNode->next = srcNode->next;
        srcNode->next = newNode;

        // Adding edge from dest to src for an undirected graph
        Node* destNode = adjacencyList[dest];
        newNode = new Node(src);
        newNode->next = destNode->next;
        destNode->next = newNode;
    }

    // Perform BFS traversal from a given source vertex considering only immediate neighbors
    void BFS(int src) {
        queue<Node*> q;
        q.emplace(adjacencyList[src]);
        adjacencyList[src]->color = "grey";
        adjacencyList[src]->distance = 0;

        while (!q.empty()) {
            Node* u = q.front();
            q.pop();
            cout << "Node " << u->data << ": Color=" << u->color << ", Distance=" << u->distance;
            if (u->predecessor) {
                cout << ", Predecessor=" << u->predecessor->data;
            }
            cout << endl;

            for (Node* v = u->next; v != nullptr; v = v->next) {
                cout << "Exploring edge: " << u->data << " -> " << v->data << endl;
                if (v->color == "white") {
                    v->color = "grey";
                    v->distance = u->distance + 1;
                    v->predecessor = u;
                    q.emplace(v);
                }
            }

            u->color = "black";
        }
        cout << "End of BFS\n";
    }
};

int main() {
    int numVertices, numEdges, sourceNode;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (source destination):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    cout << "Enter the source node: ";
    cin >> sourceNode;

    cout << "BFS Traversal starting from vertex " << sourceNode << " considering only immediate neighbors:\n";
    graph.BFS(sourceNode);

    return 0;
}

/*
Enter the source node: 0Enter the number of vertices: 5
Enter the edges (source destination): (-1 to end)
0 1
0 2
1 3
2 4
-1
Enter the source node: 0
*/
