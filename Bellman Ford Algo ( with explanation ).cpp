#include<bits/stdc++.h>
using namespace std;

int Ver,Ed;

void bellmanFord(int edge[][3],int s)
{
	int parent[Ver];		//Stores Shortest Path Structure

    int value[Ver];	    //Keeps shortest path values to each vertex from source

	for (int i = 0; i < Ver; ++i) value[i] = INT_MAX;


                    //Assuming start point as Node-0
	parent[s] = -1;	//Start node has no parent
	value[s] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices

	bool updated;
	for(int i=0;i < Ver-1;++i)
	{
		updated = false;
		for(int j=0 ; j<Ed ; ++j)
		{
			int u = edge[j][0];
			int v = edge[j][1];
			int w = edge[j][2];

			if( value[u]!=INT_MAX && value[u] + w < value[v])
			{
				value[v] = value[u]+w;
				parent[v] = u;
				updated = true;
			}
		}
		if(updated==false)
			break;
	}


	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0 ; j < Ed && updated==true ; ++j)
		{
			int u = edge[j][0];
			int v = edge[j][1];
			int w = edge[j][2];

			if( value[u]!=INT_MAX && value[u] + w < value[v])
			{
                cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}


	//Print Shortest Path Graph
	for(int i=0;i<Ver;++i)
		//cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
		cout<<i<<" <===> "<<value[i]<<endl;
}

int main()
{
	cin>>Ver>>Ed;	//Enter no of Vertices and Edges
	int edge[Ed][3];

	//Now input all Ed edges
	int src,dst,wt;

	for(int i=0;i<Ed;++i)
	{
		cin>>src>>dst>>wt;

		edge[i][0] = src;
		edge[i][1] = dst;
		edge[i][2] = wt;
	}

	int start;

	cin>>start;

	bellmanFord(edge,start);
}

/*
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
*/

//TIME COMPLEXITY: O(V.E)
