#include <stdio.h>

		   		 //A, B, C, D, E, F, G, H
int graph[8][8] = {0, 1, 0, 0, 0, 1, 1, 0,
				   1, 0, 1, 1, 0, 0, 0, 0,
				   0, 1, 0, 0, 0, 0, 0, 0,
				   0, 1, 0, 1, 0, 0, 0, 0,
				   0, 0, 0, 1, 0, 0, 0, 0,
			  	   1, 0, 0, 0, 0, 0, 0, 0,
				   1, 0, 0, 0, 0, 0, 0, 1,
				   0, 0, 0, 0, 0, 0, 1, 0};

char alpha[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
int visit[8] = {0, };

void dfs(int x)
{
	int w;
	visit[x] = 1;
	printf("[%c] ", alpha[x]);
	for(w=0; w<8; w++){
		if(!visit[w] && graph[w][x]){
			dfs(w);
		}
	}
}

int main()
{
	printf("dfs result : ");
	dfs(0);
	printf("\n");
	return 0;
}

