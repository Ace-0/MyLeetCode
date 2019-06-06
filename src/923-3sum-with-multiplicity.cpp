// 923. 3Sum With Multiplicity


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	int threeSumMulti(vector<int>& A, int target) {
		sort(A.begin(), A.end());
		int count = 0;
		for (int i = 0; i + 2 < A.size(); ++i) {
			int target_sum = target - A[i];
			int left = i + 1, right = A.size() - 1;
			while (left < right) {
				if (A[left] + A[right] < target_sum) {
					++left;
				}
				else if (A[left] + A[right] > target_sum) {
					--right;
				}
				else {
					if (A[left] == A[right]) {
						int Cn = right - left + 1;
						count = (count + Cn * (Cn - 1) / 2) % ((int)pow(10, 9) + 7);
						break;
					}
					else {
						int left_cnt = 1, right_cnt = 1;
						while ((left + 1 < right) && A[left] == A[left + 1]) {
							++left;
							++left_cnt;
						}
						while ((right - 1 > left) && A[right] == A[right - 1]) {
							--right;
							++right_cnt;
						}
						count = (count + left_cnt * right_cnt) % ((int)pow(10, 9) + 7);
						++left;
						--right;
					}
				}
			}
		}
		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<int> testcase = { 1,1,2,2,3,3,4,4,5,5 };
//	//int target = 8;
//	vector<int> testcase = { 1,1,2,2,2,2 };
//	int target = 5;
//	
//	int ans = s.threeSumMulti(testcase, target);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}