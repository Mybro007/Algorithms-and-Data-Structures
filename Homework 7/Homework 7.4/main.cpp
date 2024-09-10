#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

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

	void connectivity()
	{
		int cur = 1;
		std::vector <int> was(size, -1);
		std::queue <int> q;
		for (int i = 0; i < size; i++)
		{
			if (was[i] != -1)
			{
				continue;
			}
			q.push(i);
			while (!q.empty())
			{
				int v = q.front();
				q.pop();
				if (was[v] != -1)
				{
					continue;
				}
				was[v] = cur;
				for (int j = 0; j < size; j++)
				{
					if (adjacent[v][j] == 1 && was[j] == -1)
					{
						q.push(j);
					}
				}
			}
			cur++;
		}

		std::cout << "Belonging of vertices to connected components: \n";
		for (int i = 0; i < was.size(); i++)
		{
			std::cout << i + 1 << " - " << was[i] << "\n";
		}
		std::cout << "Number of connected components in the graph: " << --cur << "\n";
	}
};


int main()
{
	int size{};
	Graph* graph = new Graph();
	graph->connectivity();
	delete graph;
	return 0;
}