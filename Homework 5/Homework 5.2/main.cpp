#include<iostream>
#include<cmath>
#include<string>

class ActException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Wrong action!!! Try again: ";
	}
};

class UpException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Error!!! You are on root element!\n";
	}
};

class LeftException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Error!!! Left element missing!\n";
	}
};

class RightException : std::exception
{
public:
	const char* what() const noexcept override
	{
		return "Error!!! Right element missing!\n";
	}
};

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
			if (twopow && (i + 1) != 1)
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

	void print_elem(int current)
	{
		int elem_level{};
		elem_level = static_cast<int>(std::log2(current+1));
		std::cout << elem_level << " ";
		if (current == 0)
		{
			std::cout << "root " << root() << "\n";
		}
		else if (current % 2 != 0)
		{
			std::cout << "left " << "(" << data[parent_index(current)] << ") " << data[left_index(parent_index(current))] << "\n";
		}
		else
		{
			std::cout << "right " << "(" << data[parent_index(current)] << ") " << data[right_index(parent_index(current))] << "\n";
		}
	}

	void clear_mem()
	{
		delete[] data;
	}

	void travelling()
	{
		int current{ 0 };
		std::string action;
		int act;
		do
		{
			std::cout << "You are here: ";
			print_elem(current);
			std::cout << "Choose the action: \n" <<
				"- up\n" <<
				"- left\n" <<
				"- right\n" <<
				"- exit\n";
			try
			{
				std::cin >> action;
				if ((action != "up") && (action != "left") && (action != "right") && (action != "exit"))
				{
					throw ActException();
				}
			}
			catch (const ActException& ex)
			{
				while ((action != "up") && (action != "left") && (action != "right") && (action != "exit"))
				{
					std::cout << ex.what();
					std::cin >> action;
				}
			}

			if (action == "up")
			{
				act = 1;
			}
			else if (action == "left")
			{
				act = 2;
			}
			else if (action == "right")
			{
				act = 3;
			}
			else if (action == "exit")
			{
				std::cout << "Bye bye!!!\n";
				exit(0);
			}

			switch (act)
			{
				case 1:
				{
					try
					{
						if (current == 0)
						{
							throw UpException();
						}
					}
					catch (const UpException& ex)
					{
						std::cout << ex.what();
						continue;
					}

					int parent = parent_index(current);
					current = parent;
					std::cout << "Ok\n";
				}
				break;

				case 2:
				{
					try
					{
						if (2 * current + 1 >= size)
						{
							throw LeftException();
						}
					}
					catch (const LeftException& ex)
					{
						std::cout << ex.what();
						continue;
					}

					current = 2 * current + 1;
					std::cout << "Ok\n";
				}
				break;

				case 3:
				{
					try
					{
						if (2 * current + 2 >= size)
						{
							throw RightException();
						}
					}
					catch (const RightException& ex)
					{
						std::cout << ex.what();
						continue;
					}

					current = 2 * current + 2;
					std::cout << "Ok\n";
				}
				break;
			}

		} while (action != "exit");
	}
};

int main()
{
	Pyramid* pyr = new Pyramid();
	pyr->print_mass();
	pyr->print_pyr();
	pyr->travelling();
	pyr->clear_mem();
	delete pyr;
	return 0;
}