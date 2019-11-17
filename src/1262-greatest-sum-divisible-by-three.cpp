// 5264. Find Elements in a Contaminated Binary Tree


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;


class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
		for (int n : nums)
			sum += n;
		if (sum % 3 == 0)
			return sum;

		priority_queue<int> priQue1, priQue2;
		for (int n : nums) {
			if (n % 3 == 1) {
				priQue1.push(n);
				if (priQue1.size() > 3)
					priQue1.pop();
			} else if (n % 3 == 2) {
				priQue2.push(n);
				if (priQue2.size() > 3)
					priQue2.pop();
			}
		}
		if (sum % 3 == 1) {
			int removeCand1 = INT_MAX;
			if (!priQue1.empty()) {
				while (priQue1.size() != 1) {
					priQue1.pop();
				}
				removeCand1 = priQue1.top();
			}
			int removeCand2 = INT_MAX;
			if (priQue2.size() >= 2) {
				while (priQue2.size() != 2) {
					priQue2.pop();
				}
				removeCand2 = 0;
				while (!priQue2.empty()) {
					removeCand2 += priQue2.top();
					priQue2.pop();
				}
			}
			if (removeCand1 == INT_MAX && removeCand2 == INT_MAX)
				return 0;
			if (removeCand1 < removeCand2)
				return sum - removeCand1;
			else
				return sum - removeCand2;
		} else {
			int removeCand1 = INT_MAX;
			if (priQue1.size() >= 2) {
				while (priQue1.size() != 2) {
					priQue1.pop();
				}
				removeCand1 = 0;
				while (!priQue1.empty()) {
					removeCand1 += priQue1.top();
					priQue1.pop();
				}
			}
			int removeCand2 = INT_MAX;
			if (!priQue2.empty()) {
				while (priQue2.size() != 1) {
					priQue2.pop();
				}
				removeCand2 = priQue2.top();
			}
			if (removeCand1 == INT_MAX && removeCand2 == INT_MAX)
				return 0;
			if (removeCand1 < removeCand2)
				return sum - removeCand1;
			else
				return sum - removeCand2;
		}
    }

};

// int main() {
// 	Solution s = Solution();

// 	vector<int> nums1 = {3,6,5,1,8};
// 	vector<int> nums2 = {1,2,3,4,4};
// 	vector<int> nums3 = {4};

// 	int ans1 = s.maxSumDivThree(nums1);
// 	int ans2 = s.maxSumDivThree(nums2);
// 	int ans3 = s.maxSumDivThree(nums3);

// 	return 0;
// }
