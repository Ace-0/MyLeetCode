// 838. Push Dominoes


#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
	string pushDominoes(string dominoes) {
		int i, j;
		string result = "";
		for (int k = 0; k < dominoes.size(); ++k) {
			if (dominoes[k] == 'L') {
				result += 'L';
			}
			else if (dominoes[k] == 'R') {
				result += 'R';
			}
			else {
				i = k - 1;
				while (i >= 0 && dominoes[i] == '.')
					--i;
				j = k + 1;
				while (j < dominoes.size() && dominoes[j] == '.')
					++j;
				if (i >= 0 && j < dominoes.size()) {
					if (dominoes[i] == dominoes[j])
						result += dominoes[i];
					else if (dominoes[i] == 'R' && dominoes[j] == 'L' && k - i < j - k)
						result += 'R';
					else if (dominoes[i] == 'R' && dominoes[j] == 'L' && k - i > j - k)
						result += 'L';
					else
						result += '.';
				}
				else if (i == -1 && j != dominoes.size() && dominoes[j] == 'L') {
					result += 'L';
				}
				else if (i != -1 && j == dominoes.size() && dominoes[i] == 'R') {
					result += 'R';
				}
				else {
					result += '.';
				}
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = ".L.R...LR..L..";
//	
//	string ans = s.pushDominoes(testcase);
//
//	cout << ans << endl;
//	cout << "Match: " << (ans == "LL.RR.LLRRLL..") << endl;
//
//	system("pause");
//	return 0;
//}