#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define INF 999

void displayGraph(int **, int, int);
void floydWarshall (int **, int **, int);

int main(){
	clock_t tic = clock();
	int i, j, line=0, word=0;
	int row, col;\
	char ch;
	FILE *fp;

	fp = fopen("graphmat1.txt", "r");
    ch = fgetc(fp);
    while (ch != EOF){
       	ch = fgetc(fp);
		switch(ch){
			case ' ':
				if(line == 0){
					word++;
				}
				break;
			case '\n':
				line++;
				break;
			default:
				break;
		}
    }
	fclose(fp);
	row = line;
	col = word + 1;
	if(row != col){
		printf("Adjacency matrix must be a Square matrix\n");
		exit(0);
	}
	int** graph=malloc(row * sizeof(int*)); 
	for(i=0; i<row; i++){
		graph[i] = malloc(col * sizeof(int));
	}

  	FILE *file;
  	file = fopen("graphmat1.txt", "r");
 	for(i = 0; i < row; i++)
  	{
    	for(j = 0; j < col; j++) 
    	{
       		if (!fscanf(file, "%d", &graph[i][j])) 
           	break;
      	}
	}
	fclose(file);

	printf ("Adjacency matrix for the input directed Graph\n");
	displayGraph(graph, row, col);
	floydWarshall(graph, graph, row);
	clock_t toc = clock();
    printf("Time required for execution: %f seconds\n", (double)(toc - tic));
	return 0;
}


void floydWarshall (int **graph, int **dist, int V)
{
    int i, j, k;
	int** path=malloc(V * sizeof(int*)); 
	for(i=0; i<V; i++){
		path[i] = malloc(V * sizeof(int));
	}

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];


	for (int v = 0; v < V; v++) 
	{
		for (int u = 0; u < V; u++) 
		{
			//cost[v][u] = graph[v][u];

			if (v == u)
				path[v][u] = 0;
			else if (dist[v][u] != 999)
				path[v][u] = v;
			else
				path[v][u] = -1;
		}
	}


    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
            }
        }
    }
	printf ("Shortest distances between every pair of vertices \n");
    displayGraph(dist, V, V);
	printf ("Shortest path between every pair of vertices \n");
    displayGraph(path, V, V);
}


void displayGraph(int **dist, int row, int col){
	int i,j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "Inf");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
