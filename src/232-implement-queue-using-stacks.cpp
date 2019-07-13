// 232. Implement Queue using Stacks


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
public:
	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stk.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		while (stk.size() != 1) {
			temp_stk.push(stk.top());
			stk.pop();
		}
		int return_val = stk.top();
		stk.pop();
		while (!temp_stk.empty()) {
			stk.push(temp_stk.top());
			temp_stk.pop();
		}
		return return_val;
	}

	/** Get the front element. */
	int peek() {
		while (stk.size() != 1) {
			temp_stk.push(stk.top());
			stk.pop();
		}
		int return_val = stk.top();
		while (!temp_stk.empty()) {
			stk.push(temp_stk.top());
			temp_stk.pop();
		}
		return return_val;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stk.empty();
	}

private:
	stack<int> stk, temp_stk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */