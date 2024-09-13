#include<iostream>
#include<fstream>
#include<vector>

class Orgraph
{
private:
	int size{};
	int* vertices;
	std::vector <int> order;
	int** adjacent;

public:
	Orgraph()
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

	void print_order()
	{
		for (int i = 0; i < order.size(); i++)
		{
			std::cout << order[i] << " ";
		}
	}

	void dfs(int vertex, bool* visited)
	{
		visited[vertex] = true;
		for (int i = 0; i < size; i++)
		{
			if (adjacent[vertex][i] == 1 && !visited[i])
			{
				dfs(i, visited);
			}
		}
		order.insert(order.begin(), vertex+1);
	}

	void top_sort()
	{
		bool* visited = new bool[size] {0};
		for (int i = 0; i < size; i++)
		{
			if (!visited[i])
			{
				dfs(i, visited);
			}
		}
		delete[] visited;
		std::cout << "Topological order of vertices: ";
		print_order();
	}
};


int main()
{
	int size{};
	Orgraph* orgraph = new Orgraph();
	std::cout << "\n\n";
	orgraph->top_sort();
	std::cout << "\n\n";
	delete orgraph;
	return 0;
}