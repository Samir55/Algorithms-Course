#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define INTEGER_SIZE 32

// ToDo @Samir55 Implement most significant digit radix sort.

class radix_bit {
	private:
	const int bit;
	public:
	radix_bit (int b) : bit(b) {
	}
	
	bool operator ()(int value) const {
		// Check the sign bit and return true (means the element sholud be swapped to the right of the vector) if it's negative.
		if (bit == 31) 
			return value < 0;
		else
			return !(value & (1 << bit)); // 0 bit to left partition
	}
};

/// Radix Sort. 
void radix_sort (vector<int>& vec) {
	lp (least_sig_bit, INTEGER_SIZE) {
		stable_partition(vec.begin(), vec.end(), radix_bit(least_sig_bit));
	}
} 
 
int main()
{
    vector<int> test_vec = { 22, 99, 365, -984, -802, 12, 55, 0, 88 };
 
    radix_sort(test_vec);
    
    cout << "{ ";
    lp(i, test_vec.size()) {
		cout << test_vec[i] << " ";
	}
	cout << "}" << endl;
 
    return 0;
}
