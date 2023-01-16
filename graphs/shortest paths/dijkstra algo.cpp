#include<bits/stdc++.h>
using namespace std;
#define V 9
typedef pair<int,int> iPair;


void dijkstra(int graph[][V],int src)
{
    int dist[V];
    //bool sptSet[V];

    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    vector<int> parents(V);

    for(int i=0;i<V;i++)
    {
        parents[i]=i;
    }

    //memset(sptSet,false,sizeof(sptSet));
    
    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(dist[src],src));

    while(!pq.empty())
    {
        //int distance=pq.top().first;
        int vertex=pq.top().second;
        pq.pop();

        for(int i=0;i<V;i++)
        {
           if(graph[vertex][i]!= 0 && graph[vertex][i]!= INT_MAX && dist[i]>dist[vertex]+graph[vertex][i])
           {
            dist[i]=dist[vertex]+graph[vertex][i];
            pq.push(make_pair(dist[i],i));
            parents[i]=vertex;
           }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

    vector<int> path;
    int node=V-1;
    while(parents[node]!=node)
    {
        path.push_back(node);
        node=parents[node];
    }
    path.push_back(0);
    reverse(path.begin(),path.end());
    for(auto it : path)
    {
        cout<<it<<"-";
    }
}


int main()
{
     int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph,0);
}

/*
void dijkstra(int graph[][V],int src)
{
    int dist[V];
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

    for(int i=0;i<V;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[src] = 0;
    pq.push(make_pair(dist[src],src));

    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();

        for(auto it : graph[u])
        {
            int v=it.first;
            int w=it.second;

            if(dist[v]>dist[u]+weight)
             {
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
             }
        }
    }






*/