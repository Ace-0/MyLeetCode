// 809. Expressive Words


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
		vector<char> chVal;
		vector<int> chCnt;
		S.push_back('.');
		int start = 0;
		for (int i = 1; i < S.length(); ++i) {
			if (S[i] != S[i - 1]) {
				chVal.push_back(S[i - 1]);
				chCnt.push_back(i - start);
				start = i;
			}
		}
        int count = 0;
		for (string& word : words) {
			word.push_back('.');
			int start = 0;
			int curCnt = 0;
			int sIdx = 0;
			int i = 1;
			for (; i < word.length() && sIdx != chVal.size(); ++i) {
				if (word[i] != word[i - 1]) {
					curCnt = i - start;
					if (word[i - 1] != chVal[sIdx]) {
						break;
					}
					if (chCnt[sIdx] >= 3 && curCnt > chCnt[sIdx]) {
						break;
					}
					if (chCnt[sIdx] < 3 && curCnt != chCnt[sIdx]) {
						break;
					}
					start = i;
					++sIdx;
				}
			}
			if (sIdx == chVal.size() && i == word.length()) {
				++count;
			}
		}
		return count;
    }
};

int main() {
	Solution s = Solution();

	string S = "heeellooo";
	vector<string> testcase = {"hello", "hi", "helo"};
	
	int ans = s.expressiveWords(S, testcase);

	cout << ans << endl;

	return 0;
}