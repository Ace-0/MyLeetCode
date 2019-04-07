// 326. Power of Three


#include <iostream>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		return (n > 0 && 1162261467 % n == 0);
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 81;
//	
//	bool ans = s.isPowerOfThree(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}