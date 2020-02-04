#include "QuickSort.h"

void quickSortWork(int firstIndex, int lastIndex, std::vector<int>& v);


std::vector<int> quickSort(std::vector<int> v) {
	quickSortWork(0, v.size()-1, v);
	return v;
}

void quickSortWork(int firstIndex, int lastIndex, std::vector<int>& v) {

	if (firstIndex < lastIndex) {
		int pivot = v[lastIndex];									//pivot is the last element
		int pivotIndex = lastIndex;									//index of pivot
		int i = firstIndex;
		int j = lastIndex;

		/*for (int i = pivotIndex - 1; i >= firstIndex; --i) {
			
			if (v[i] > pivot) {
				int temp = v[i];
				for (int j = i; j < lastIndex; ++j) {
					v[j] = v[j + 1];
				}
				v[lastIndex] = temp;
				pivotIndex = pivotIndex - 1;
			}
		}*/

		while (i < j) {
			if (v[i] < pivot)
				++i;
			else {
				while ((i != j) && (v[j] > pivot))
					--j;
				std::swap(v[i], v[j]);
			}
			++i;
		}

		quickSortWork(firstIndex, pivotIndex - 1, v);
		quickSortWork(pivotIndex + 1, lastIndex, v);
	}
}


