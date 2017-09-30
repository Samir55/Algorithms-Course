#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
int main() { 
	string t, s;
	cin >> s;
	t = s;
	reverse(t.begin(), t.end());
	if (s == t) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
