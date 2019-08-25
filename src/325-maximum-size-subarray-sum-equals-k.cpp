// 325. Maximum Size Subarray Sum Equals k


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int max_len = 0, cur_sum = 0;
		unordered_map<int, int> hash_map;
		hash_map[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			cur_sum += nums[i];
			int target = cur_sum - k;
			if (hash_map.find(target) != hash_map.end())
				max_len = max(max_len, i - hash_map[target]);
			if (hash_map.find(cur_sum) == hash_map.end())
				hash_map[cur_sum] = i;
		}
		return max_len;
    }
};
