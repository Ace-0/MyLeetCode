class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int h = matrix.size();
		if (h == 0)
			return 0;
		int w = matrix[0].size();
		int max_area = 0;
		// record of every row
		vector<int> to_left(w, 0);
		vector<int> to_right(w, w - 1);
		vector<int> height(w, 0);

		for (int i = 0; i < h; ++i) {
			
			for (int j = 0; j < w; ++j) {
				if (matrix[i][j] == '1')
					height[j] += 1;
				else
					height[j] = 0;
			}
			int cur_left = 0;
			for (int j = 0; j < w; ++j) {
				if (matrix[i][j] == '1')
					to_left[j] = max(to_left[j], cur_left);  // the rightmost
				else {
					cur_left = j + 1;
					to_left[j] = 0;  // so that this value have no influence on to_left[j] in the next row
				}
			}

			int cur_right = w - 1;
			for (int j = w - 1; j >= 0; --j) {
				if (matrix[i][j] == '1')
					to_right[j] = min(to_right[j], cur_right);  // the leftmost
				else {
					cur_right = j - 1;
					to_right[j] = w - 1;  // so that this value have no influence on to_right[j] in the next row
				}
			}

			for (int j = 0; j < w; ++j) {
				int cur_area = (to_right[j] - to_left[j] + 1) * height[j];
				if (cur_area > max_area)
					max_area = cur_area;
			}
		}
		return max_area;
	}
};
