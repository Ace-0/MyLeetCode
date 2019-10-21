// 482. License Key Formatting


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int chCnt = 0;
        for (char ch : S) {
            if (ch != '-') {
				++chCnt;
			}
        }
		if (chCnt == 0) {
			return "";
		}
        int length = chCnt + (chCnt % K == 0 ? chCnt / K - 1 : chCnt / K);
		string result(length, '\0');
		int j = length - 1;
		int cnt = 0;
		for (int i = S.length() - 1; i >= 0; --i) {
			if (cnt == K) {
				result[j] = '-';
				--j;
				cnt = 0;
			}
			if (S[i] == '-') {
				// do nothing
			}
			else if (S[i] >= 'a' && S[i] <= 'z') {
				result[j] = S[i] - 32;
				--j;
				++cnt;
			}
			else {
				result[j] = S[i];
				--j;
				++cnt;
			}
		}
		return result;
    }
};

// int main() {
// 	Solution s = Solution();

// 	string testcase = "5F3Z-2e-9-w";
// 	int k = 4;
	
// 	string ans = s.licenseKeyFormatting(testcase, k);

// 	cout << ans << endl;

// 	return 0;
// }