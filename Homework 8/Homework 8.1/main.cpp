#include<iostream>
#include<fstream>

class Orgraph
{
private:
	int size{};
	int* vertices;
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

	void printer()
	{
		std::cout << "Text view of orgraph: \n";
		for (int i = 0; i < size; i++)
		{
			std::cout << i + 1 << ": ";
			int counter{0};
			for (int j = 0; j < size; j++)
			{
				if (adjacent[i][j] == 1)
				{
					counter++;
					std::cout << j+1 << " ";
				}
			}

			if(counter == 0)
			{
				std::cout << "no\n";
			}
			else
			{
				std::cout << "\n";
			}
		}
	}
};


int main()
{
	int size{};
	Orgraph* orgraph = new Orgraph();
	orgraph->printer();
	delete orgraph;
	return 0;
}