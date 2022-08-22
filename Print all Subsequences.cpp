#include<bits/stdc++.h>
using namespace std;

void printSubsequencesUsingBacktracking(int i, string s, string substr, vector<string> &allSubs) {
//base case
	if (i == s.size()) {
		allSubs.push_back(substr);
		return;
	}
	substr += s[i]; //add the character to form a subsequence
	printSubsequencesUsingBacktracking(i + 1, s, substr, allSubs);
	substr.pop_back();
	printSubsequencesUsingBacktracking(i + 1, s, substr, allSubs);
}


//using concept of power set - TC = O(2^n*n)
void printSubsequencesUsingPowerSet(string s, vector<string> &allSubs) {
// using the concept of ith bit is set or not - n&(1<<i)
	int n = s.size(), range = 1 << n;/*power of 2*/
	for (int num = 0; num < range; num++) {
		string substr;
		for (int pos = 0; pos < n; pos++) {
			int checkIthBit = num & (1 << pos);
			if (checkIthBit != 0) {
				substr += s[pos];
			}
		}
		allSubs.push_back(substr);
	}
}


int main() {
	string s;
	cin >> s;
	vector<string> allSubs;
	/*	printSubsequencesUsingBacktracking(0, s, "", allSubs);
		for (string &subs : allSubs) cout << subs << " ";*/

	printSubsequencesUsingPowerSet(s, allSubs);
	for (string &subs : allSubs) cout << subs << " ";
	return 0;
}

@singhkunal01
