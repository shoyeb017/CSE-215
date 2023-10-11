#include<bits/stdc++.h>
using namespace std;

#define V 4
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
	int parent[V];
	int value[V];
	bool processed[V];

	for (int i = 0; i < V; ++i)
    {
        value[i] = INT_MAX;
        processed[i]=false;
    }

	parent[s] = -1;
	value[s] = 0;

	for(int i=0;i<V-1;++i)       	//Relaxtion V-1 times
	{
		int U = selectMinVertex(value,processed);
		processed[U] = true;

		for(int j=0;j<V;++j)
		{
			if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && (value[U]+graph[U][j] < value[j]) )
			{
				value[j] = value[U] + graph[U][j];
				parent[j] = U;
			}
		}
	}

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
