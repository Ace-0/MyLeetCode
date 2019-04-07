// 202. Happy Number

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> set;
		while (n != 1) {
			string str = to_string(n);
			n = 0;
			for (char ch : str)
				n += (ch - '0') * (ch - '0');
			if (set.find(n) != set.end())
				break;
			set.insert(n);
		}
		return n == 1;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int testcase = 18;
//	
//	int ans = s.isHappy(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}