#include <stdio.h> 
#include <stdlib.h>

struct Edge 
{ 
    int src;
	int dest;
	int weight; 
}; 

struct Graph 
{ 
    int V;
	int E; 
    Edge* edge; 
}; 
  
struct subset 
{ 
    int parent; 
    int order; 
}; 

int find(struct subset [], int i); 
void Sollin(struct Graph*);
int countVertex(int a[1000]);

struct Graph* graph;

int main() 
{             
    int edge=0;
    int help_to_count[1000];
    scanf("%d", &edge);
    
	for(int i=0; i<1000; i++)
	{
		help_to_count[i]=-9999;
	}
    
    struct Graph* graph = new Graph;  
    graph->E = edge; 
    graph->edge = new Edge[edge];     
  
  	int source_G, destination_G, weight_G;
  	for(int i=0;i<edge;i++)
  	{
	  	scanf("%d %d %d",&source_G,&destination_G,&weight_G);
	  	
	  	help_to_count[source_G]=1;
	  	help_to_count[destination_G]=1;
	  	
	    graph->edge[i].src = source_G; 
	    graph->edge[i].dest = destination_G; 
	    graph->edge[i].weight = weight_G;   
	}
	
//	printf("現在有vertex數:%d",countVertex(help_to_count));
	
	graph->V=countVertex(help_to_count);
  
  	printf("--------The answer--------\n");
    Sollin(graph); 
  
    return 0; 
} 
  
void Sollin(struct Graph* graph) 
{ 
    Edge *edge = graph->edge; 
    struct subset *subsets = new subset[graph->V]; 
    int *lowest = new int[graph->V]; 
  	int numTrees = graph->V; 
  	int j;
    for (j = 0; j < graph->V; ++j) 
    { 
        subsets[j].parent = j; 
        subsets[j].order = 0; 
        lowest[j] = -99999; 
    } 
  
    while (numTrees > 1) 
    { 
        for (j = 0; j < graph->V; ++j) 
            lowest[j] = -99999; 

        for (j=0; j<graph->E; j++) 
        { 
            int set1 = find(subsets, edge[j].src); 
            int set2 = find(subsets, edge[j].dest); 
  
            if (set1 == set2) continue; 
            else
            { 
               if (lowest[set1] == -99999) 
                 lowest[set1] = j; 
				 
               if (edge[lowest[set1]].weight > edge[j].weight) 
                 lowest[set1] = j; 				  
  
               if (lowest[set2] == -99999) 
                 lowest[set2] = j; 
                 
               if (edge[lowest[set2]].weight > edge[j].weight) 
                 lowest[set2] = j;                  
            } 
        } 

        for (j=0; j<graph->V; j++) 
        { 
            if (lowest[j] != -99999) 
            { 
                int set1 = find(subsets, edge[lowest[j]].src); 
                int set2 = find(subsets, edge[lowest[j]].dest); 
  
                if (set1 == set2) 
                    continue; 
                printf("%d %d %d\n",edge[lowest[j]].src, edge[lowest[j]].dest, edge[lowest[j]].weight); 
  
			    int root_x = find(subsets, set1); 
			    int root_y = find(subsets, set2); 
			  
			    if (subsets[root_x].order < subsets[root_y].order) 
			        subsets[root_x].parent = root_y; 
			    else if (subsets[root_x].order > subsets[root_y].order) 
			        subsets[root_y].parent = root_x; 
			    else
			    { 
			        subsets[root_y].parent = root_x; 
			        subsets[root_x].order++; 
			    }                 
                numTrees--; 
            } 
        } 
    } 
    return; 
} 
  
int find(struct subset subsets[], int i) 
{ 
	int rev;
    if (subsets[i].parent != i) 
      subsets[i].parent = find(subsets, subsets[i].parent); 
    
    rev=subsets[i].parent;
  
    return rev; 
} 

int countVertex(int a[1000])
{
	int total_count=0;
	for(int i=0; i<1000; i++)
	{
		if(a[i]!=-9999)
		total_count++;
	}
	
	return total_count;
}
