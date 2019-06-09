// 316. Remove Duplicate Letters


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> remain(26, 0);
		vector<bool> exist(26, false);
		for (int i = 0; i < s.length(); ++i)
			++remain[s[i] - 'a'];

		string result = "";
		for (int i = 0; i < s.length(); ++i) {
			if (!exist[s[i] - 'a']) {
				while (!result.empty() && s[i] < result.back() && remain[result.back() - 'a'] > 0) {
					exist[result.back() - 'a'] = false;
					result.pop_back();
				}
				result.push_back(s[i]);
				exist[s[i] - 'a'] = true;
			}
			--remain[s[i] - 'a'];
		}
		return result;
	}
};
