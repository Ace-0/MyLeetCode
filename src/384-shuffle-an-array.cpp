// 384. Shuffle an Array

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

class Solution {
public:
	Solution(vector<int> nums) {
		original_array = nums;
		srand(time(NULL));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original_array;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int length = original_array.size();
		vector<bool> used(length, false);
		vector<int> shuffled = original_array;
		for (int i = 1; i < length; ++i) {
			int random = rand() % (i + 1);
			swap(shuffled[i], shuffled[random]);
		}
		
		return shuffled;
	}
private:
	vector<int> original_array;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

//int main() {
//	vector<int> testcase = { 1,2,3,4 };
//	
//	Solution s = Solution(testcase);
//
//	vector<int> s1 = s.shuffle();
//	vector<int> s2 = s.shuffle();
//	vector<int> s3 = s.reset();
//	for (int x : s1)
//		cout << x << ' ';
//	cout << endl;
//	for (int x : s2)
//		cout << x << ' ';
//	cout << endl;
//	for (int x : s3)
//		cout << x << ' ';
//	cout << endl;
//	system("pause");
//	return 0;
//}