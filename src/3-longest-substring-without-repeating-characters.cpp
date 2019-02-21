// 39ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_length = s.length();
		if (max_length == 0) {
			return 0;
		}

		vector<int> length(max_length, 0);
		map<char, int> last_position;
		int answer = 1;
		length[0] = 1;
		last_position[s[0]] = 0;

		for (int i = 1; i < max_length; i++) {
			if (last_position.find(s[i]) != last_position.end() && last_position.at(s[i]) >= i - 1 - length[i - 1]) {
				length[i] = i - last_position[s[i]];
			}
			else {
				length[i] = length[i - 1] + 1;
			}
			last_position[s[i]] = i;
			
			if (length[i] > answer) {
				answer = length[i];
			}
		}
		return answer;
	}
};

// 46ms
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_length = s.length();
		if (max_length == 0) {
			return 0;
		}

		vector<int> length(max_length, 0);
		vector<int> left_most(max_length, 0);
		map<char, int> last_position;
		int answer = 1;
		length[0] = 1;
		last_position[s[0]] = 0;

		for (int i = 1; i < max_length; i++) {
			if (last_position.find(s[i]) != last_position.end() && last_position.at(s[i]) >= left_most[i - 1]) {
				length[i] = i - last_position[s[i]];
				left_most[i] = last_position[s[i]] + 1;
			}
			else {
				length[i] = length[i - 1] + 1;
				left_most[i] = left_most[i - 1];
			}
			last_position[s[i]] = i;
			if (length[i] > answer) {
				answer = length[i];
			}
		}
		//for (int i = 0; i < max_length; i++) {
		//	cout << left_most[i] << ' ';
		//}
		//cout << endl;
		//for (int i = 0; i < max_length; i++) {
		//	cout << length[i] << ' ';
		//}
		//cout << endl;
		return answer;
	}
};
