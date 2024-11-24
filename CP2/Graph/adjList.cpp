#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    vector<int> adjList[n];
    cout<<"Enter the number of edges: ";
    int e;
    cin>>e;
    cout<<"Enter the edges: " << endl;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cout<<"Adjacency List: " << endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -> ";
        for(int j=0;j<adjList[i].size();j++)
        {
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}