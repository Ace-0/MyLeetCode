// 1043. Partition Array for Maximum Sum


#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int maxSumAfterPartitioning(vector<int>& A, int K) {
		vector<int> max_sum(A.size(), 0);
		max_sum[0] = A[0];
		for (int i = 1; i < max_sum.size(); ++i) {
			// cur_max_val is the max value in partition [i - k + 1, i]
			int cur_max_val = 0;
			// j is the size of the last partition
			for (int j = 1; j <= K && j <= i + 1; ++j) {
				cur_max_val = max(A[i - j + 1], cur_max_val);
				if (j == i + 1)
					max_sum[i] = max(cur_max_val * j, max_sum[i]);
				else
					max_sum[i] = max(max_sum[i - j] + cur_max_val * j, max_sum[i]);
			}
		}
		return max_sum[A.size() - 1];
	}
};

//int main() {
//	Solution s = Solution();
//
//	int K = 3;
//	vector<int> testcase = { 1,15,7,9,2,5,10 };
//
//	int ans = s.maxSumAfterPartitioning(testcase, K);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
