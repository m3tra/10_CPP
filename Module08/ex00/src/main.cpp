#include "easyfind.hpp"

int main() {
	std::vector<int> vec1;
	vec1 = { 1, 3, 5, 7, 11};

	try
	{
		std::vector<int>::iterator it = easyfind(vec1, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
