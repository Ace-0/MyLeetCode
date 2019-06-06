// 845. Longest Mountain in Array


#include <iostream>
#include <vector>

using namespace std;

//// O(n) two pass
//class Solution {
//public:
//	int longestMountain(vector<int>& A) {
//		vector<int> left(A.size(), 0), right(A.size(), 0);
//		for (int i = 1, j = A.size() - 2; i < A.size(); ++i, --j) {
//			if (A[i] > A[i - 1])
//				left[i] = left[i - 1] + 1;
//			if (A[j] > A[j + 1])
//				right[j] = right[j + 1] + 1;
//		}
//		int max_len = 0;
//		for (int i = 0; i < A.size(); ++i) {
//			if (left[i] > 0 && right[i] > 0 && left[i] + right[i] + 1 > max_len)
//				max_len = left[i] + right[i] + 1;
//		}
//		return max_len;
//	}
//};

// O(n) one pass
class Solution {
public:
	int longestMountain(vector<int>& A) {
		int start = 0, end = 0, max_len = 0;
		while (start < A.size()) {
			end = start;
			while (end + 1 < A.size() && A[end + 1] > A[end])
				++end;
			if (end > start && end + 1 < A.size() && A[end + 1] < A[end]) {
				while (end + 1 < A.size() && A[end + 1] < A[end])
					++end;
				max_len = end - start + 1 > max_len ? end - start + 1 : max_len;
			}
			start = end > start + 1 ? end : start + 1;
		}
		return max_len;
	}
};
//
//int main() {
//	Solution s = Solution();
//
//	//vector<int> testcase = { 2,1,4,7,3,2,5 };
//	vector<int> testcase = { 3, 2 };
//
//	int ans = s.longestMountain(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}