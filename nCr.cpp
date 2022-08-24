#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int solvenCr(int n, int r, vector<vector<int>> &dp) {
	//base cases
	if (n < r) return 0;
	if (r == 1 or r == n - 1) return n; // like 5C4 == 5C1 == n
	if (dp[n][r] != -1) return dp[n][r];
	int reduceR = solvenCr(n - 1, r - 1, dp);
	int notReduceR = solvenCr(n - 1, r, dp);
	return dp[n][r] = (reduceR % mod + notReduceR % mod) % mod;
}
int nCr(int n, int r) {
	/*memoisation approach */
	vector<vector<int>> dp(n + 1, vector<int> (r + 1, -1));
	return (long long)solvenCr(n, r, dp) % mod;
}

int main() {
	int n, r;
	cin >> n >> r;
	cout << nCr(n, r);
	return 0;

}
