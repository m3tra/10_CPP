#include "easyfind.hpp"

void	testVector() {
	std::cout << ORANGE "Vector" WHITE << std::endl;

	int arr[] = { 1, 2, 3, 5, 7 };
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "vec: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	easyfind(vec, 5);
	easyfind(vec, 6);
}

void	testDeque() {
	std::cout << ORANGE "Double-ended queue" WHITE << std::endl;

	int arr[] = { 11, 13, 17, 19, 23 };
	std::deque<int> queue(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "queue: ";
	for (std::deque<int>::iterator it = queue.begin(); it != queue.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	easyfind(queue, 5);
	easyfind(queue, 13);
}

void	testList() {
	std::cout << ORANGE "List" WHITE << std::endl;

	int arr[] = { 29, 31, 37, 41, 43 };
	std::list<int> list(arr, arr + sizeof(arr) / sizeof(arr[0]));

	std::cout << "list: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	easyfind(list, 5);
	easyfind(list, 41);
}

int main() {
	testVector();
	std::cout << std::endl;
	testDeque();
	std::cout << std::endl;
	testList();

	return 0;
}
