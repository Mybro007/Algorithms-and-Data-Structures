#include<iostream>

class Pyramid
{
private:
	int size{ 10 };
	int level{ 0 };
	int* data = new int[size] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};

	int root()
	{
		return data[0];
	}

	int from_index(int index)
	{
		return data[index];
	}

	int left_index(int parent_index)
	{
		return 2 * parent_index + 1;
	}

	int right_index(int parent_index)
	{
		return 2 * parent_index + 2;
	}

	int parent_index(int child_index)
	{
		return(child_index - 1) / 2;
	}

public:
	void print_mass()
	{
		std::cout << "Massive: ";
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << " ";
		}
		std::cout << "\n";
	}

	void print_pyr()
	{
		bool twopow = false;
		std::cout << "Pyramid: \n";
		for (int i = 0; i < size; i++)
		{
			twopow = (i + 1) && !((i + 1) & ((i + 1) - 1));
			if (twopow && (i+1)!=1)
			{
				level++;
			}
			std::cout << level << " ";
			if (i == 0)
			{
				std::cout << "root " << root() << "\n";
			}
			else if (i % 2 != 0)
			{
				std::cout << "left " << "(" << data[parent_index(i)] << ") " << data[left_index(parent_index(i))] << "\n";
			}
			else
			{
				std::cout << "right " << "(" << data[parent_index(i)] << ") " << data[right_index(parent_index(i))] << "\n";
			}
		}
	}

	void clear_mem()
	{
		delete[] data;
	}
};

int main()
{
	Pyramid* pyr = new Pyramid();
	pyr->print_mass();
	pyr->print_pyr();
	pyr->clear_mem();
	delete pyr;
	return 0;
}