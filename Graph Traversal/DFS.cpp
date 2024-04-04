#include <iostream>
#include <vector>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 100

struct Node {
    int data;
    Node* next;
};

struct Graph {
    int numVertices;
    Node* adjLists[MAX_NODES];
    int color[MAX_NODES];
    int pi[MAX_NODES];
    int d[MAX_NODES];
    int f[MAX_NODES];
    int time;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = new Graph;
    graph->numVertices = numVertices;
    graph->time = 0;

    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i] = nullptr;
        graph->color[i] = WHITE;
        graph->pi[i] = -1;
        graph->d[i] = 0;
        graph->f[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFSVisit(Graph* graph, int vertex) {
    graph->time++;
    graph->d[vertex] = graph->time;
    graph->color[vertex] = GRAY;

    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    while (temp != nullptr) {
        int connectedVertex = temp->data;

        if (graph->color[connectedVertex] == WHITE) {
            graph->pi[connectedVertex] = vertex;
            DFSVisit(graph, connectedVertex);
        }
        temp = temp->next;
    }

    graph->color[vertex] = BLACK;
    graph->time++;
    graph->f[vertex] = graph->time;
}

void DFS(Graph* graph, int startVertex) {
    DFSVisit(graph, startVertex);
}

int main() {
    // Input the number of vertices
    int numVertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    // Create a graph with the given number of vertices
    Graph* graph = createGraph(numVertices);

    // Input the edges of the graph
    int numEdges;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    std::cout << "Enter the edges (source destination):\n";
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        std::cin >> src >> dest;
        addEdge(graph, src, dest);
    }

    // Input the starting vertex for DFS
    int startVertex;
    std::cout << "Enter the starting vertex for DFS: ";
    std::cin >> startVertex;

    std::cout << "Depth First Search:\n";
    DFS(graph, startVertex);

    std::cout << "Vertex\t\n";
    for (int i = 0; i < graph->numVertices; i++) {
        std::cout << i << "\n";
    }

    delete graph;

    return 0;
}
