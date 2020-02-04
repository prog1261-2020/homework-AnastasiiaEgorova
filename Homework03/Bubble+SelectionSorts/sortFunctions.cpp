#include "sortFunctions.h"

std::vector<int> bsort(const std::vector<int>& v) {

	std::vector<int> tmpV;
	tmpV = v;
	bool swapped;

	for (int i = 0; i < tmpV.size()-1; ++i) {				//outer element		
		swapped = false;
		for (int j = 0; j < tmpV.size()-i-1; ++j) {
			if (tmpV[j] > tmpV[j+1]) {
				std::swap(tmpV[j], tmpV[j+1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
	return tmpV;
}

std::vector<int> selectionSort(const std::vector<int>& v) {

	std::vector<int> tmpV = v;

	for (int i = 0; i < tmpV.size()-1; ++i) {
		int min = tmpV[i];
		int k = i;
		for (int j = i + 1; j < tmpV.size(); ++j) {
			if (tmpV[j] < min) {
				min = tmpV[j];
				k = j;
			}
		}
		if (k != i) {
			std::swap(tmpV[i], tmpV[k]);
		}
	}
	return tmpV;
}