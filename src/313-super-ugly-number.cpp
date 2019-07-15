// 313. Super Ugly Number


#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		int k = primes.size();
		vector<int> pri_idx2ugly_idx(k, 0), super_ugly(n, INT_MAX);
		super_ugly[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < k; ++j)
				super_ugly[i] = min(primes[j] * super_ugly[pri_idx2ugly_idx[j]], super_ugly[i]);
			for (int j = 0; j < k; ++j)
				if (primes[j] * super_ugly[pri_idx2ugly_idx[j]] == super_ugly[i])
					++pri_idx2ugly_idx[j];
		}
		return super_ugly[n - 1];
	}
};

int main() {
	Solution s = Solution();

	vector<int> testcase = { 2,7,13,19 };
	int k = 12;
	
	int ans = s.nthSuperUglyNumber(k, testcase);

	cout << ans << endl;

	system("pause");
	return 0;
}