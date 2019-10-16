/**
 * @file     insertion_sort.cpp
 * @author   Student Name
 * @version  Feb 17, 2019
 * John Quan
 * @brief
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

void insertionSort(std::vector<int> & data) {
	// TODO Write the code for insertionSort

//	1. For each element, with the second element as the current element
//	2. If the previous element is bigger than the current element
//	3. Temporarily save the current element

	for (size_t i {1}; i < data.size(); i++) {
		cout << "comparing data.at(i), " << data.at(i) << ", to data.at(i - 1), " << data.at(i - 1) << endl;
		if (data.at(i - 1) > data.at(i)) {
			cout << data.at(i - 1) << " > " << data.at(i) << endl;
			cout << "Moving backwards" << endl;
			cout << endl;

			int temp;
			temp = data.at(i);
			cout << "temp = " << data.at(i);
			cout << endl;
			
			cout << "Current state: data.at(i): " << data.at(i) << ", data.at(i - 1): " << data.at(i - 1) << ", temp: " << temp << endl;
			cout << endl;
	// Now, we need to move each element that is bigger than the temporary.

//	4. Make a new index j for decrementing equal to the current index
//	5. While j isn't zero and the previous element is greater than the
//        temporarily saved element
//	6. Move the previous element into the current element
//	7. Decrement j
			cout << "Setting j to i: " << i << endl;
			cout << endl;
			int j = i;

			cout << "Precheck for (data.at(j - 1) > temp): " << data.at(j - 1) << " > " << temp << endl;
			while (j > 0 && (data.at(j - 1) > temp)) {
				cout << "Current j: " << j << ", and (data.at(j - 1) > temp): (" << data.at(j - 1) << " > " << temp << ")" << endl;
				cout << endl;


				cout << "data.at(j - 1): " << data.at(j - 1) << " data.at(j): " << data.at(j) << " temp: " << temp << endl;
				cout << "data.at(j 1) = data.at(j - 1): " << data.at(j) << " = " << data.at(j - 1);
				cout << endl;
				data.at(j) = data.at(j - 1); 
				cout << "after move, data.at(j): " << data.at(j) << ", and data.at(j - 1): " << data.at(j - 1) << endl;
				j--;
			}

	// We found where temp goes.

//	8. Move it into the element at j
			cout << "Moving final element into data.at(j): " << data.at(j) << ", temp: " << temp << endl;
			data.at(j) = temp;
		}
	}
}

bool isEqual(const std::vector<int> & v1, const std::vector<int> & v2) {
	// compare lengths
	if (v1.size() != v2.size()) {
		return false;
	}
	// compare elements
	for (unsigned long i = 0; i < v1.size(); ++i) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}
	// must be the same
	return true;
}

void printVector(const std::vector<int>& vec) {
	for (const auto& element : vec) {
		std::cout << element << ' ';
	}
}
