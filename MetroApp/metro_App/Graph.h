#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <string>

using namespace std;
// Jeremy's Part
//  Constant representing infinity
const int INF = numeric_limits<int>::max();

// Graph Class Definition
class Graph
{
public:
    int vertices;

    vector<vector<pair<int, int>>> adjacencyList; // making a pair of vectors with the name: "adjacencyList"

    // Constructor to initialize the graph with a given number of vertices
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight)
    {
        adjacencyList[u].push_back(make_pair(v, weight)); // pairing u with v by pushing v and its weight to u
        adjacencyList[v].push_back(make_pair(u, weight)); // pairing v with u by pushing u and its weight to v
    }

    // Dijkstra's algorithm to find the shortest paths from a given station (vertex)
    vector<int> dijkstra(int start, vector<int> &parent)
    {

        // Initialize distances to all vertices as infinity except the start vertex
        vector<int> distance(vertices, INF);
        distance[start] = 0;

        // Priority queue to store vertices based on their distances
        // The pair is (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, start));

        // Main loop of Dijkstra's algorithm
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // Iterate over neighbors of the current vertex
            for (const auto &neighbor : adjacencyList[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path to v is found through u
                if (distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                    parent[v] = u; // update parent in shortest path tree
                    pq.push(make_pair(distance[v], v));
                }
            }
        }
        // Return the acquired distances
        return distance;
    }

    // Function to construct and return the path from start to end using the parent array
    string getPath(int start, int end, const vector<int> &parent)
    {
        string path = to_string(end);
        // Construct the path into a sequential format
        while (end != start)
        {
            end = parent[end];
            path = to_string(end) + "->" + path;
        }
        return path;
    }

    // Function to find and return the shortest path tree from a given start node
    vector<int> getShortestPathTree(int start)
    {
        vector<int> parent(vertices, -1); // Initialize parent array

        dijkstra(start, parent); // Call Dijkstra's algorithm to find the shortest path tree

        return parent; // Return the parent array representing the shortest path tree
    }
};