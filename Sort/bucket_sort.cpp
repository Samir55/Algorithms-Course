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
#define lp(i, n)   for(int i=0;i<(int)(n);++i)

void bucket_sort(vector<float> & vec) {
	
	// Create n buckets.
	vector<vector<float>> buckets;
	buckets.resize(vec.size());
	
	// Populate the buckets.
	lp(i, vec.size()) {
		int i_bucket = vec[i] * vec.size();
		buckets[i_bucket].push_back(vec[i]);
	}
	
	// Insertion sort over the ll buckets (Or we can use stl sort function to choose the best sorting algorithm).
	lp(i, vec.size()) {
		sort(buckets[i].begin(), buckets[i].end());
	}
	
	// Update the vector with the sorted elements.
	int i_vec = 0;
	lp(i, vec.size()){
		lp(j, buckets[i].size()) {
			vec[i_vec++] = buckets[i][j];
		}
	}
}

int main() {
	//~ freopen("input.txt", "r", stdin); 
	vector<float> test_vec = { 0.22, 0.99, 0.365, 0.984, 0.802, 0.12, 0.55, 0.0, 0.88 };
 
    bucket_sort(test_vec);
    
    cout << "{ ";
    lp(i, test_vec.size()) {
		cout << test_vec[i] << " ";
	}
	cout << "}" << endl;
 
	return 0;
}
