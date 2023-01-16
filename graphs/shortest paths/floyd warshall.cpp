#include<bits/stdc++.h>
using namespace std;

#define INF 9999
#define V 4


void floydWarshall(int **graph)
{
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(graph[i][j]>graph[k][j]+graph[i][k] && graph[k][j]!=INF && graph[i][k]!=INF)
                {
                    graph[i][j]=graph[k][j]+graph[i][k];
                }
            }
        }
    }

    cout<<endl;
    
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<graph[i][j]<<"\t";
        }

        cout<<endl;
    }

}

int main()
{
    int a;
    int b;
    int w;      
    int edges;
    cin>>edges;

    int** graph=new int*[V];
    
    for(int i=0;i<V;i++)
    {
        graph[i]=new int[V];
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
           if(i!=j)
            graph[i][j]=INF;
           else
            graph[i][j]=0;
        }
    }

    for(int i=0;i<edges;i++)
    {
        cin>>a>>b>>w;
        graph[a][b]=w;
    }

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<graph[i][j]<<"\t";
        }

        cout<<endl;
    }

    floydWarshall(graph);


}