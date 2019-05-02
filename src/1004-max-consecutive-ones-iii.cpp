// 1004. Max Consecutive Ones III


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int start = 0, end = 0, k = K, max_len = 0;  // [start, end)
		while (end < A.size()) {
			if (A[end] == 1) {
				++end;
			}
			else {
				if (k > 0) {
					--k;
					++end;
				}
				else {
					max_len = end - start > max_len ? end - start : max_len;
					while (A[start] != 0)
						++start;
					++start;
					++end;
				}
			}
		}
		return end - start > max_len ? end - start : max_len;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	vector<int> testcase = { 0,0,0,1 };
//	
//	int ans = s.longestOnes(testcase, 4);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}