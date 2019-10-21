// 1055. Shortest Way to Form String


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, srcLen = source.length(), tarLen = target.length();
		int result = 0;
		bool hasMatched = true;
		while (j < tarLen && hasMatched) {
			++result;
			hasMatched = false;
			for (i = 0; i < srcLen && j < tarLen; ++i) {
				if (source[i] == target[j]) {
					++j;
					hasMatched = true;
				}
			}
		}
		if (j == tarLen) {
			return result;
		}
		else {
			return -1;
		}
    }
};

// int main() {
// 	Solution s = Solution();

// 	string source = "xyz";
// 	string target = "xzyxz";
	
// 	int ans = s.shortestWay(source, target);

// 	cout << ans << endl;

// 	return 0;
// }