#include <iostream>
#include <vector>
#include <queue>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INFINITY 9999
#define MAX_NODES 100

struct Node {
    int data;
    Node* next;
};

struct Graph {
    int numVertices;
    std::vector<Node*> adjLists;
    std::vector<int> color;
    std::vector<int> d;
    std::vector<int> pi;
};

struct Queue {
    int front, rear;
    int capacity;
    int* array;
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
    graph->adjLists.resize(numVertices, nullptr);
    graph->color.resize(numVertices, WHITE);
    graph->d.resize(numVertices, INFINITY);
    graph->pi.resize(numVertices, -1);
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

Queue* createQueue(int capacity) {
    Queue* queue = new Queue;
    queue->capacity = capacity;
    queue->front = -1;
    queue->rear = -1;
    queue->array = new int[capacity];
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

bool isFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    if (isEmpty(queue))
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return item;
}

void BFS(Graph* graph, int startVertex) {
    Queue* queue = createQueue(graph->numVertices);
    graph->color[startVertex] = GRAY;
    graph->d[startVertex] = 0;
    graph->pi[startVertex] = -1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int u = dequeue(queue);
        Node* temp = graph->adjLists[u];
        while (temp != nullptr) {
            int v = temp->data;
            if (graph->color[v] == WHITE) {
                graph->color[v] = GRAY;
                graph->d[v] = graph->d[u] + 1;
                graph->pi[v] = u;
                enqueue(queue, v);
            }
            temp = temp->next;
        }
        graph->color[u] = BLACK;
    }

    delete[] queue->array;
    delete queue;
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

    // Input the starting vertex for BFS
    int startVertex;
    std::cout << "Enter the starting vertex for BFS: ";
    std::cin >> startVertex;

    std::cout << "Breadth First Search:\n";
    BFS(graph, startVertex);

    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < graph->numVertices; i++) {
        std::cout << i << "\t" << graph->d[i] << "\n";
    }

    delete graph;

    return 0;
}
