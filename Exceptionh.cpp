// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

bool sfpa(int V, int src, int Edges[][3],
		int M)
{
	// Stores the adjacency list of
	// the given graph
	vector<pair<int, int> > g[V];

	// Create Adjacency List
	for (int i = 0; i < M; i++) {

		int u = Edges[i][0];
		int v = Edges[i][1];
		int w = Edges[i][2];

		g[u].push_back({ v, w });
	}

	// Stores the distance of all
	// reachable vertex from source
	vector<int> dist(V, INT_MAX);

	// Check if vertex is present
	// in queue or not
	vector<bool> inQueue(V, false);

	// Counts the relaxation for
	// each vertex
	vector<int> cnt(V, 0);

	// Distance from src to src is 0
	dist[src] = 0;

	// Create a queue
	queue<int> q;

	// Push source in the queue
	q.push(src);

	// Mark source as visited
	inQueue[src] = true;

	while (!q.empty()) {

		// Front vertex of Queue
		int u = q.front();
		q.pop();

		inQueue[u] = false;

		// Relaxing all edges of
		// vertex from the Queue
		for (pair<int, int> x : g[u]) {

			int v = x.first;
			int cost = x.second;

			// Update the dist[v] to
			// minimum distance
			if (dist[v] > dist[u] + cost) {

				dist[v] = dist[u] + cost;

				// If vertex v is in Queue
				if (!inQueue[v]) {
					q.push(v);
					inQueue[v] = true;
					cnt[v]++;

					// Negative cycle
					if (cnt[v] >= V)
						return true;
				}
			}
		}
	}

	// No cycle found
	return false;
}

// Driver Code
int main()
{
	// Number of vertices
	int N = 4;

	// Given source node src
	int src = 0;

	// Number of Edges
	int M = 4;

	// Given Edges with weight
	int Edges[][3] = { { 0, 1, 1 },
					{ 1, 2, -1 },
					{ 2, 3, -1 },
					{ 3, 0, -1 } };

	// If cycle is present
	if (sfpa(N, src, Edges, M) == true)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

