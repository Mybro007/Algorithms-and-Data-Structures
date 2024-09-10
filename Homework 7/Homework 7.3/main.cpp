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

		vertices = new int[size];
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

	bool dfs(int vertex, bool* visited, int prev = 0)
	{
		visited[vertex] = true;
		for (int i = 0; i < size; i++)
		{
			if (adjacent[vertex][i] == 1)
			{
				if (!visited[i])
				{
					dfs(i, visited, vertex);
				}
				else if (i != prev)
				{
					return true;
				}
			}
		}
		return false;
	}

	void is_cyclic()
	{
		bool* visited = new bool[size] {0};
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				if (dfs(i,visited))
				{
					delete[]visited;
					std::cout << "There is a cycle in this graph\n";
					exit(0);
				}
			}
		}
		delete[]visited;
		std::cout << "There are no cycles in this graph\n";
		exit(0);
	}
};


int main()
{
	int size{};
	Graph* graph = new Graph();
	graph->is_cyclic();
	delete graph;
	return 0;
}