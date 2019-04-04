#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;
		vector<int> cnts(26, 0);
		for (char ch : s)
			cnts[ch - 'a'] += 1;
		for (char ch : t) {
			if (cnts[ch - 'a'] == 0)
				return false;
			cnts[ch - 'a'] -= 1;
		}
		return true;
	}
};
