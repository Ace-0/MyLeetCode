// 930. Binary Subarrays With Sum


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numSubarraysWithSum(vector<int>& A, int S) {
		int start_i = 0, start_j = 0, end = 0, count = 0, sum_i = 0, sum_j = 0;
		for (end = 0; end < A.size(); ++end) {
			sum_i += A[end];
			while (start_i < end && sum_i > S) {
				sum_i -= A[start_i];
				start_i += 1;
			}

			sum_j += A[end];
			while (start_j < end && (sum_j > S || (sum_j == S && A[start_j] == 0))) {
				sum_j -= A[start_j];
				start_j += 1;
			}

			if (sum_i == S)
				count += start_j - start_i + 1;
		}

		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> A = { 0,0,0,0,0 };
//	int S = 0;
//	
//	int ans = s.numSubarraysWithSum(A, S);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}