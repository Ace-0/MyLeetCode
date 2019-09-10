// 440. K-th Smallest in Lexicographical Order


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findKthNumber(int n, int k) {
		int result = 1;
		while (k > 1) {
			int count = 0;  // number in [first, min(n + 1, last))
			for (long first = result, last = result + 1; first <= n; first *= 10, last *= 10) {
				count += min((long)n + 1, last) - first;
			}
			if (count < k) {
				k -= count;
				result += 1;
			}
			else {
				k -= 1;
				result *= 10;
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int n = 10;
//	int k = 3;
//	
//	int ans = s.findKthNumber(n, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}