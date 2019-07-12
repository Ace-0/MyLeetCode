// 201. Bitwise AND of Numbers Range


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int move_cnt = 0;
		while (m != n) {
			m >>= 1;
			n >>= 1;
			++move_cnt;
		}
		m <<= move_cnt;
		return m;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int m = 5;
//	int n = 7;
//	/*
//		0101
//		0110
//		0111
//	*/
//	
//	int ans = s.rangeBitwiseAnd(m, n);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}