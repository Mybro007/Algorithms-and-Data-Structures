#include<iostream>
#include<fstream>

class Graph
{
private:
	int size{};
	int* vertices;
	int** adjacent;

public:
	Graph()
	{
		std::ifstream fin("input.txt");
		if (!fin.is_open())
		{
			std::cout << "File with data doesn't exist!\n";
			exit(-1);
		}
		fin >> size;

		vertices = new int [size];
		for (int i = 0; i < size; i++)
		{
			vertices[i] = i + 1;
		}

		adjacent = new int* [size];
		for (int i = 0; i < size; i++)
		{
			adjacent[i] = new int[size];
		}

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				fin >> adjacent[i][j];
			}
		}
		fin.close();
	}

	void dfs()
	{
		bool* visited = new bool[size]{0};
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				dfs(i, visited);
			}
		}
		delete []visited;
	}

	void dfs(int vertex, bool* visited)
	{
		visited[vertex] = true;
		std::cout << vertices[vertex] << " ";
		for (int i = 0; i < size; i++)
		{
			if (adjacent[vertex][i] == 1 && !visited[i])
			{
				dfs(i, visited);
			}
		}
	}
};


int main()
{
	int size{};
	Graph* graph = new Graph();
	graph->dfs();
	delete graph;
	return 0;
}