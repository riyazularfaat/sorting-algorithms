#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adjList)
{
    vector<bool> visited(adjList.size(), false); // Keep track of visited nodes
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
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

    bfs(0, adjList); // Start BFS from node 0
    return 0;
}