#include <iostream>
#include <stdlib.h>
#include <vector>

template<typename T>
void merge(std::vector<T>& arr, const int l, const int mid, const int r){
	const int n1 = mid - l + 1;
	const int n2 = r - mid;
	std::vector<T> left(n1), right(n2);
	for(int i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for(int i = 0; i < n2; i++)
		right[i] = arr[mid + 1 + i];

	int i = 0, j = 0, k = l;

	while(i < n1 && j < n2){
		if (left[i] <= right[j])
			arr[k] = left[i++];
		else
			arr[k] = right[j++];
		k++;
	}

	while(i < n1)
		arr[k++] = left[i++];
	while(j < n2)
		arr[k++] = right[j++];
}

template<typename T>
void mergeSort(std::vector<T>& arr, const int l, const int r){
	if(l >= r)
		return;

	const int mid = l + (r - l)/2;

	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);

	merge(arr, l, mid, r);

}

void printVector(std::vector<int>& vec){
	for (auto t: vec)
		std::cout << t << " ";
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

	mergeSort(massive, 0, massive.size() - 1);

	printVector(massive);

	return 0;
}