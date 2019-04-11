// 334. Increasing Triplet Subsequence


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int smallest = INT_MAX, sec_smallest = INT_MAX;
		for (int n : nums)
			if (n <= smallest)
				smallest = n;
			else if (n <= sec_smallest)
				sec_smallest = n;
			else
				return true;
		return false;
	}
};
