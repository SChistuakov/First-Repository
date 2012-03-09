// 8.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <limits.h>

int read(FILE *file)
{
	int tmp = 0;
	fscanf(file, "%d", &tmp);
	return tmp;
}

void newGraph(int *graph[], int town)
{
	for(int i = 0; i < town; i++)
		for(int j = 0; j < town; j++)
			graph[i][j] = 0;
}

void inputGraph(FILE *file, int*graph[], int road)
{
	int k = 0;
	int l = 0;
	for(int i = 0; i < road; i++)
	{
		fscanf(file, "%d", &k);
		fscanf(file, "%d", &l);
		fscanf(file, "%d", &graph[k - 1][l - 1]);
		graph[l - 1][k - 1] = graph[k - 1][l - 1];
	}
}

void create(int visit[], int way[], int town)
{
	for (int i = 0; i < town; i++)
	{
		way[i] = INT_MAX;
		visit[i] = 0;
	}
	way[0] = 0;
	visit[0] = 1;
}

void search(int *graph[], int visit[], int way[], int town)
{
	int current = 0;
	bool flag = true;
	while(flag)
	{
		for(int i = 0; i < town; i++)
			if((graph[current][i] != 0) && (visit[i] == 0) && (way[i] > way[current] + graph[current][i]))
				way[i] = way[current] + graph[current][i];
		int dist = INT_MAX;
		flag = false;
		for(int i = 0; i < town; i++)
		{
			if((visit[i]) == 0 && (way[i] < dist))
			{
				flag = true;
				current = i;
				dist = way[i];
			}
		}
		visit[current] = 1;
	}
}

void print(int way[], int town)
{
	for(int j = 0; j < town; j++)
	{
		int min = INT_MAX;
		int imin = 0;
		for(int i = 0; i < town; i++)
		{
			if((way[i] < min) && (way[i] >= 0))
			{
				min = way[i];
				imin = i;
			}
		}
		printf("town number %d way %d\n",imin + 1, min);
		way[imin] = -1;
	}
}

int main()
{
	FILE *file;
	file = fopen("txt.txt","r");

	int town = read(file);
	int road = read(file);

	int **graph = new int*[town];

	for(int i = 0; i < town; i++)
		graph[i] = new int[town];

	newGraph(graph, town);

	inputGraph(file, graph, road);

	int *visit = new int[town];
	int *way = new int[town];

	create(visit, way, town);

	search(graph, visit, way, town);

	print(way, town);

	for (int i = 0; i < town; i++)
		delete[]graph[i];

	delete[]graph;
	delete[]visit;
	delete[]way;

	fclose(file);
	return 0;
}
