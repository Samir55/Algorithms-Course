//http://sites.math.rutgers.edu/~ajl213/CLRS/Ch24.pdf
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

/// Heapify function: create the max heap from the vector of elemetns.
void heapify(vector<int> &vec, int n, int i) {
	int biggest = i;
	int left = 2 * i + 1; // Get the left child element.
	int right = 2 * i + 2; // Get the right child element.
	
	if (left < n && vec[left] > vec[biggest]) {
		biggest = left;
	}
	
	if (right < n && vec[right] > vec[biggest]) {
		biggest = right;
	}
	
	if (biggest != i) { // Swaping elements must be made.
		swap(vec[biggest], vec[i]);
		heapify(vec, n, biggest);
	}
}

// We shall sort the elements in an ascending order.
/// Heap sort algorithm.
void heap_sort(vector<int> &vec) {
	int n = vec.size();
	// Build the max heap.
	for (int i = n / 2 -1; i >= 0; i--) {
		heapify(vec, n, i);
	}	
	// Swap the first and the last element then call heapify to refix the max heap.
	for (int i = n - 1; i >=0; i--) {
		swap (vec[i], vec[0]);
		heapify(vec, i, 0);
	} 
}

int main() {
	// Testing.
	vector<int> test_vec = {11, 22, 333, 1, 2, 3, 99, 0, 0, 11};
	heap_sort(test_vec);
	cout << "{ ";
	lp(i, test_vec.size()) {
		cout << test_vec[i] << " ";
	}
	cout << "}" << endl;
return 0;
}
