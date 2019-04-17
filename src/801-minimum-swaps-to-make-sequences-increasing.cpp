// 801. Minimum Swaps To Make Sequences Increasing


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int minSwap(vector<int>& A, vector<int>& B) {
		int pre_natural = 0, pre_swap = 1;
		for (int i = 1; i < A.size(); ++i) {
			int cur_natural = INT_MAX, cur_swap = INT_MAX;
			if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
				cur_natural = min(cur_natural, pre_natural);  // if [i-1]s are natural, [i]s are natural
				cur_swap = min(cur_swap, pre_swap + 1);       // if [i-1]s are swapped, [i]s can be swapped
			}
			if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
				cur_swap = min(cur_swap, pre_natural + 1);    // if [i-1]s are natural, [i]s can be swapped
				cur_natural = min(cur_natural, pre_swap);     // if [i-1]s are swapped, [i]s are natural
			}
			pre_natural = cur_natural;
			pre_swap = cur_swap;
		}
		return min(pre_natural, pre_swap);
	}
};
