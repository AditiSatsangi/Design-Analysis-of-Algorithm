// C++ Program for Floyd Warshall Algorithm
#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4
#define INF 99999

// A function to print the solution matrix
void printSolution(int dist[][V]);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V])
{

	int i, j, k;

	for (k = 0; k < V; k++) {
		// Pick all vertices as source one by one
		for (i = 0; i < V; i++) {
			// Pick all vertices as destination for the
			// above picked source
			for (j = 0; j < V; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])
					&& (dist[k][j] != INF
						&& dist[i][k] != INF))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	cout << "Matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	
	int graph[V][V] = { { 0, 5, INF, 10 },
						{ 2, 0, 3, 5 },
						{ 0, INF, 0, 1 },
						{ 0, 5, INF, 0 } };

	// Function call
	floydWarshall(graph);
	return 0;
}

