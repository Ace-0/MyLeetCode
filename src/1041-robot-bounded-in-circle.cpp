// 5055. Robot Bounded In Circle


#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
	bool isRobotBounded(string instructions) {
		// N:0 E:1 S:2 W:3
		int cur_direction = 0, cur_row = 0, cur_col = 0;
		for (char ch : instructions) {
			if (ch == 'G') {
				if (cur_direction == 0)
					--cur_row;
				else if (cur_direction == 1)
					++cur_col;
				else if (cur_direction == 2)
					++cur_row;
				else
					--cur_col;
			}
			else {
				cur_direction = ch == 'L' ? cur_direction - 1 : cur_direction + 1;
				if (cur_direction == -1)
					cur_direction = 3;
				if (cur_direction == 4)
					cur_direction = 0;
			}
		}
		if (cur_direction == 0 && (cur_row != 0 || cur_col != 0))
			return false;
		else
			return true;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "GG";
//
//	bool ans = s.isRobotBounded(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
