#include<iostream>
#include<fstream>
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

	void bfs()
	{
		std::cout << "There are " << size << " vertex in graph. From which vertex you want to start algorithm: ";
		int initial{};
		std::cin >> initial;
		bool* visited = new bool[size] {0};
		std::queue<int>* q = new std::queue<int>;
		q->push(initial-1);
		while (!(q->empty()))
		{
			int vertex = q->front();
			q->pop();
			std::cout << vertex + 1 << " ";
			visited[vertex] = true;
			for (int j = 0; j < size; j++)
			{
				if (adjacent[vertex][j] == 1 && !visited[j])
				{
					q->push(j);
					visited[j] = true;
				}
			}
		}
		delete q;
		delete[]visited;
	}
};


int main()
{
	int size{};
	Graph* graph = new Graph();
	graph->bfs();
	delete graph;
	return 0;
}