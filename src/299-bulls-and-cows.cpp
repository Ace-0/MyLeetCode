class Solution {
public:
	string getHint(string secret, string guess) {
		int length = secret.length();
		if (length == 0) {
			return "0A0B";
		}
		vector<int> count(10, 0);
		vector<bool> visited(length, false);
		int bulls = 0, cows = 0;

		for (int i = 0; i < length; i++) {
			if (guess[i] == secret[i]) {
				bulls++;
				visited[i] = true;
			}
			else {
				count[secret[i] - '0']++;
			}
		}
		for (int i = 0; i < length; i++) {
			if (visited[i] == false && count[guess[i] - '0'] > 0) {
				cows++;
				count[guess[i] - '0']--;
			}
		}
		char* str = new char[256];
		sprintf(str, "%1dA%1dB", bulls, cows);
		string answer = str;
		return answer;
	}
};