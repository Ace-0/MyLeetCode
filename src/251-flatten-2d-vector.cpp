// 251. Flatten 2D Vector


#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
public:
	Vector2D(vector<vector<int>>& v) {
		end = v.end();
		i = v.begin();
		if (i != end) {
			j = i->begin();
			while (i != end && j == i->end()) {
				++i;
				if (i != end)
					j = i->begin();
			}
		}
		vec = v;
	}

	int next() {
		int val = *j;
		++j;
		while (i != end && j == i->end()) {
			++i;
			if (i != end)
				j = i->begin();
		}
		return val;
	}

	bool hasNext() {
		return i != end;
	}
private:
	vector<vector<int>> vec;
	vector<vector<int>>::iterator i, end;
	vector<int>::iterator j;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

//int main() {
//	vector<vector<int>> vec = { {} };
//	Vector2D iterator(vec);
//	
//	//cout << iterator.next() << endl; // return 1
//	//cout << iterator.next() << endl; // return 2
//	//cout << iterator.next() << endl; // return 3
//	//cout << iterator.hasNext() << endl; // return true
//	//cout << iterator.hasNext() << endl; // return true
//	//cout << iterator.next() << endl; // return 4
//	cout << iterator.hasNext() << endl; // return false
//
//	system("pause");
//	return 0;
//}