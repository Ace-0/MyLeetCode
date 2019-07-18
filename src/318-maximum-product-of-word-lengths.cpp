// 318. Maximum Product of Word Lengths


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int n = words.size();
		vector<int> bitmaps(n, 0);
		for (int i = 0; i < n; ++i) {
			for (char ch : words[i]) {
				bitmaps[i] |= (1 << (ch - 'a'));
			}
		}
		int max_pdt = 0;
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (((bitmaps[i] & bitmaps[j]) == 0) && (words[i].length() * words[j].length() > max_pdt))
					max_pdt = words[i].length() * words[j].length();
			}
		}
		return max_pdt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> testcase = { "abcw","baz","foo","bar","xtfn","abcdef" };
//	
//	int ans = s.maxProduct(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}