#include <iostream>
#include <vector>

void printVector(std::vector<int>& vec){
	for (auto t: vec)
		std::cout << t << " ";
}

template<class T>
void intersectionSort(std::vector<T>& array){
	for (size_t i = 1; i < array.size(); ++i)
	{
		const T key = array[i];
		int j = i - 1;

		for ( ; j >= 0 && array[j] > key; --j)
			array[j + 1] = array[j];
		array[j + 1] = key;
		// printVector(array);
		// std::cout << std::endl;
	}
}


int main(int argc, char const *argv[])
{
	
	int size = 0;
	std::vector<int> massive;

	std::cin >> size;

	massive.resize(size);

	for(auto& t: massive){
		std::cin >> t;
	}

	// std::cout << "Entered data: ";
	// printVector(massive);
	// std::cout << " end data" << std::endl;

	intersectionSort(massive);

	printVector(massive);


	return 0;
}
