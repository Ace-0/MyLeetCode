// 398. Random Pick Index


#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

class Solution {
public:
	Solution(vector<int>& nums) {
		srand(time(NULL));
		vec = nums;
	}

	int pick(int target) {
		int result = -1, range = 0;
		for (int i = 0; i < vec.size(); ++i) {
			if (vec[i] == target) {
				++range;
				if (rand() % range == 0)
					result = i;
			}
		}
		return result;
	}
private:
	vector<int> vec;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* int param_1 = obj->pick(target);
*/
