// 1025. Divisor Game


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool divisorGame(int N) {
		vector<int> win_vec(1001, 0);
		win_vec[1] = -1;
		return first_win(N, win_vec);
	}

	bool first_win(int N, vector<int>& win_vec) {
		if (win_vec[N] != 0) {
			return win_vec[N] == 1 ? true : false;
		}

		int factor = N / 2;
		bool second_win = true;
		while (factor >= 1) {
			if (N % factor == 0) {
				second_win &= first_win(N - factor, win_vec);
			}
			--factor;
		}

		win_vec[N] = !second_win;
		return win_vec[N];
	}
};
