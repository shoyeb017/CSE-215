#include<bits/stdc++.h>
using namespace std;

#define V 4		//No of vertices

int graph[V][V]={0};


int selectMinVertex(int value[],bool processed[])
{
	int minimum = INT_MAX;
	int vertex;
	for(int i=0;i<V;++i)
	{
		if(processed[i]==false && value[i]<minimum)
		{
			vertex = i;
			minimum = value[i];
		}
	}
	return vertex;
}


void dijkstra(int s)
{
	int parent[V];		//Stores Shortest Path Structure
	int value[V];	    //Keeps shortest path values to each vertex from source
	bool processed[V];	//TRUE->Vertex is processed

	for (int i = 0; i < V; ++i)
    {
        value[i] = INT_MAX;
        processed[i]=false;
    }

                    //Assuming start point as Node-0
	parent[s] = -1;	//Start node has no parent
	value[s] = 0;	//start node has value=0 to get picked 1st

                    //Include (V-1) edges to cover all V-vertices
	for(int i=0;i<V-1;++i)
	{
                    //Select best Vertex by applying greedy method
		int U = selectMinVertex(value,processed);
		processed[U] = true;	//Include new Vertex in shortest Path Graph

                    //Relax adjacent vertices (not yet included in shortest path graph)
		for(int j=0;j<V;++j)
		{
			/* 3 conditions to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in shortest path graph
			      3.Edge weight is smaller than current edge weight
			*/
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j] < value[j]) )
			{
				value[j] = value[U] + graph[U][j];
				parent[j] = U;
			}
		}
	}
                //Print Shortest Path Graph
	for(int i=0;i<V;++i)
		//cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
		cout<<i<<" <===> "<<value[i]<<endl;
}


int main()
{
    int ver,edge,u,v,w,s;

	cin>>ver>>edge;

	for(int i=0 ; i < edge ; i++)
    {
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }

    cin>>s;

	dijkstra(s);
}

/*
4 4
0 1 24
0 3 20
0 2 3
2 3 12
0

(Vertics 4 tah global declare)
*/

//TIME COMPLEXITY: O(V^2)
//TIME COMPLEXITY: (using Min-Heap + Adjacency_List): O(ElogV)
