// 755. Pour Water


#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	vector<int> pourWater(vector<int>& heights, int V, int K) {
		for (int i = 0; i < V; ++i) {
			int cur_height = heights[K];
			int left_min = heights[K], left_min_idx = K;
			for (int i = K - 1; i >= 0 && heights[i] <= heights[i + 1]; --i) {
				if (heights[i] < left_min) {
					left_min = heights[i];
					left_min_idx = i;
				}
			}
			int right_min = heights[K], right_min_idx = K;
			for (int i = K + 1; i < heights.size() && heights[i] <= heights[i - 1]; ++i) {
				if (heights[i] < right_min) {
					right_min = heights[i];
					right_min_idx = i;
				}
			}
			if (left_min_idx != K) {
				++heights[left_min_idx];
			}
			else if (right_min_idx != K) {
				++heights[right_min_idx];
			}
			else {
				++heights[K];
			}
		}
		return heights;
	}
};
