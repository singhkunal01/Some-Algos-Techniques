#include<bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int num) {
	vector<bool> markNotPrime(num + 1, false);
	for (int i = 2; i <= sqrt(num); i++) {
		//check whether the current number is marked or not if not then
		if (!markNotPrime[i]) {
			//mark all the multiples of current number as non prime because they all are the multiples
			for (int j = i * i; j <= num; j += i) {
				markNotPrime[j] = true;
			}
		}
	}
	for (int i = 2; i <= num; i++) 
    if (!markNotPrime[i]) 
      cout << i << " , ";
}

int main() {
	int num;
	cin >> num;
	sieveOfEratosthenes(num);
	return 0;
}
