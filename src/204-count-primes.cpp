// 204. Count Primes


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 24ms 11.6MB
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		bool* isPrime = new bool[n];
		memset(isPrime, true, n);
		for (int i = 2; i < n; ++i) {
			if (isPrime[i]) {
				++count;
				for (int j = 2; i * j < n; ++j) {
					isPrime[i * j] = false;
				}
			}
		}
		delete[] isPrime;
		return count;
	}
};

//// 80ms 8.7MB
//class Solution {
//public:
//	int countPrimes(int n) {
//		int count = 0;
//		vector<bool> isPrime(n, true);
//		for (int i = 2; i < n; ++i) {
//			if (isPrime[i]) {
//				++count;
//				for (int j = 2; i * j < n; ++j) {
//					isPrime[i * j] = false;
//				}
//			}
//		}
//		return count;
//	}
//};
