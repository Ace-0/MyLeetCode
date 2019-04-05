// 341. Flatten Nested List Iterator

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class NestedIterator {
public:
	NestedIterator(vector<NestedInteger> &nestedList) {
		this->vec_begins.push(nestedList.begin());
		this->vec_ends.push(nestedList.end());
	}

	int next() {
		return (this->vec_begins.top()++)->getInteger();
	}

	bool hasNext() {
		while (!this->vec_begins.empty()) {
			if (this->vec_begins.top() == this->vec_ends.top()) {
				// finish iterating a nested list
				this->vec_begins.pop();
				this->vec_ends.pop();
			}
			else {
				vector<NestedInteger>::iterator top = this->vec_begins.top();
				if (top->isInteger()) {
					return true;
				}
				else {
					++(this->vec_begins.top());
					this->vec_begins.push(top->getList().begin());
					this->vec_ends.push(top->getList().end());
				}
			}
		}

		return false;
	}
private:
	// Use vector.begin() and vector.end() to represect a list(vector).
	// If it is an integer, a duplicate(maybe) end() will be stored in stacks.
	stack<vector<NestedInteger>::iterator> vec_begins;
	stack<vector<NestedInteger>::iterator> vec_ends;
};