// 1138. Alphabet Board Path


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	string alphabetBoardPath(string target) {
		unordered_map<char, int> char2row, char2col;
		for (int i = 0; i < 26; ++i) {
			char2row['a' + i] = i / 5;
			char2col['a' + i] = i % 5;
		}
		string result = "";
		char cur_ch = 'a';
		int cur_r = 0, cur_c = 0, next_r = -1, next_c = -1;
		for (char& ch : target) {
			next_r = char2row[ch];
			next_c = char2col[ch];
			while (next_c < cur_c) {
				--cur_c;
				result += 'L';
			}
			while (next_r > cur_r) {
				++cur_r;
				result += 'D';
			}
			while (next_r < cur_r) {
				--cur_r;
				result += 'U';
			}
			while (next_c > cur_c) {
				++cur_c;
				result += 'R';
			}
			result += '!';
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string target = "zdz";
//
//	string ans = s.alphabetBoardPath(target);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
