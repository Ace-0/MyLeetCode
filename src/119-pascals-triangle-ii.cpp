// 119. Pascal's Triangle II


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> line(rowIndex + 1, 0);
		line[rowIndex] = 1;
		for (int row = 1; row <= rowIndex; ++row) {
			for (int i = rowIndex - row; i < rowIndex; ++i)
				line[i] += line[i + 1];
		}
		return line;
	}
};
