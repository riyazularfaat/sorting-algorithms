#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>> &adjList, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            dfsUtil(neighbor, adjList, visited);
        }
    }
}

void dfs(int start, vector<vector<int>> &adjList)
{
    vector<bool> visited(adjList.size(), false); // Keep track of visited nodes
    cout << "DFS Traversal: ";
    dfsUtil(start, adjList, visited);
    cout << endl;
}

int main()
{
    int n = 6; // Number of nodes
    vector<vector<int>> adjList(n);

    // Example graph: Add edges
    adjList[0] = {1, 2};
    adjList[1] = {0, 3, 4};
    adjList[2] = {0, 4};
    adjList[3] = {1, 5};
    adjList[4] = {1, 2};
    adjList[5] = {3};

    dfs(0, adjList); // Start DFS from node 0
    return 0;
}