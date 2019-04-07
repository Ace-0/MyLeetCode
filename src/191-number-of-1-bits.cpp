// 191. Number of 1 Bits


#include <iostream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0) {
			n = n & (n - 1);
			count += 1;
		}
		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	unsigned int testcase = 11;
//	
//	int ans = s.hammingWeight(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}