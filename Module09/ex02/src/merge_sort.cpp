#include "PmergeMe.hpp"
// Function to merge left and right subarrays of arr.
void	merge_sorted_sub_arrays(size_t l_sub_arr[], size_t r_sub_arr[], size_t arr[], size_t mid, size_t rest)
{
	size_t	left_i = 0;
	size_t	right_i = 0;
	size_t	arr_i = 0;

	while (left_i < mid && right_i < rest) {
		if (l_sub_arr[left_i] <= r_sub_arr[right_i])
			arr[arr_i] = l_sub_arr[left_i++];
		else
			arr[arr_i] = r_sub_arr[right_i++];
		arr_i++;
	}

	// ? Only needed if odd number?
	// copy remaining elements of l_sub_arr[]
	while (left_i < mid)
		arr[arr_i++] = l_sub_arr[left_i++];

	// copy remaining elements of r_sub_arr
	while (right_i < rest)
		arr[arr_i++] = r_sub_arr[right_i++];
}

void	merge_sort(size_t arr[], size_t size)
{
	if (size == 0 || size == 1)
		return;

	size_t	mid = size / 2;
	size_t	rest = size - mid;

	size_t	l_sub_arr[mid];
	size_t	r_sub_arr[rest];

	size_t	arr_i = 0;
	for (size_t i = 0; i < mid; i++)
		l_sub_arr[i] = arr[arr_i++];

	for (size_t i = 0; i < rest; i++)
		r_sub_arr[i] = arr[arr_i++];

	merge_sort(l_sub_arr, mid);
	merge_sort(r_sub_arr, rest);
	merge_sorted_sub_arrays(l_sub_arr, r_sub_arr, arr, mid, rest);

	return;
}

int	main()
{
	size_t	arr[] = {14, 17, 22, 4, 1, 5};
	size_t	size = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, size);

	std::cout << "Sorted array: ";
	for(size_t i = 0; i < size; i++)
		std::cout << arr[i] << " ";

	return 0;
}
