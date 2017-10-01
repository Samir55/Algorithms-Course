#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)
#define MAXSTRINGSIZE 20
#define NUMBEROFSTRINGS 100
#define MINNUMBEROFPALINDROMES 40
string allowed = "abcdefghiklmnopqrstuvwxyz";

string generateRandomString(int n) {
	string ret = "";
	while (n <= 0) n = rand()%MAXSTRINGSIZE;
	lp(i, n) {
		char c = allowed[rand()%allowed.size()];
		ret += c;
	}
	return ret;
}

int main() {
	srand (time(NULL));
	ofstream file_input, file_output;
	file_input.open("testcases.in");
	file_output.open("testcases.out");
	int c =  0;
	int max_number_of_palindromes = MINNUMBEROFPALINDROMES + rand()%10;

	lp(i, NUMBEROFSTRINGS) {
		if (c <= max_number_of_palindromes) {
			// Generate a palindrome string.
			string s = "";
			s = generateRandomString(rand()%MAXSTRINGSIZE);
			string t = s;
			reverse(t.begin(), t.end());
			file_input << s << t << endl;
			file_output << "YES" << endl;
			c++;
		} else {
			// Generate a non palindrome string.
			int m = rand()%MAXSTRINGSIZE;
			string s = generateRandomString(m);
			file_input << s << (s[0]-'a'+2)%allowed.size() << endl;
			file_output << "NOs" << endl;
		}
	}
	file_input.close();
	file_output.close();
	return 0;
}
