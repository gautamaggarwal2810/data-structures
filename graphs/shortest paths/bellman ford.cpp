#include<bits/stdc++.h>
using namespace std;


void BellmanFord(int graph[][3],int V,int E,int src)
{
    int dist[V];
    
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[src]=0;
   
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<E;j++)
        {
            if(dist[graph[j][0]]!=INT_MAX && dist[graph[j][1]] > dist[graph[j][0]]+graph[j][2])
             dist[graph[j][1]] = dist[graph[j][0]]+graph[j][2];
        }
    }

    for(int j=0;j<E;j++)
    {
        if(dist[graph[j][0]]!=INT_MAX && dist[graph[j][1]] > dist[graph[j][0]]+graph[j][2])
            {
                dist[graph[j][1]] = dist[graph[j][0]]+graph[j][2];
                cout<<"Negative cycle found";
            } 
    }
    cout << "Vertex Distance from Source" << endl;
        for (int i = 0; i < V; i++)
         cout << i << "\t\t" << dist[i] << endl;
}

int main()
{
    int V = 5; 
    int E = 8; 
    int graph[][3] = { { 0, 1, -100 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 },
                       { 1, 4, 2 }, { 3, 2, 5 },
                       { 3, 1, 1 }, { 4, 3, -3 } };
 
    BellmanFord(graph, V, E, 0);
}