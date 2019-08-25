// 670. Maximum Swap


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
		string num_str = to_string(num);
        vector<int> last_appr(10, -1);
		for (int i = 0; i < num_str.length(); ++i) {
			last_appr[num_str[i] - '0'] = i;
		}
		for (int i = 0; i < num_str.length(); ++i) {
			for (int j = 9; j > num_str[i] - '0'; --j) {
				if (last_appr[j] > i) {
					num_str[last_appr[j]] = num_str[i];
					num_str[i] = '0' + j;
					return stoi(num_str);
				}
			}
		}
		return num;
    }
};
