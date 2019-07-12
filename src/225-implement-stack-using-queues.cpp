// 225. Implement Stack using Queues


#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
		using_que_a = true;
	}

	/** Push element x onto stack. */
	void push(int x) {
		if (this->using_que_a)
			que_a.push(x);
		else
			que_b.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int return_value;
		if (this->using_que_a) {
			while (!que_a.empty()) {
				if (que_a.size() == 1) {
					return_value = que_a.front();
					que_a.pop();
					break;
				}
				que_b.push(que_a.front());
				que_a.pop();
			}
		}
		else {
			while (!que_b.empty()) {
				if (que_b.size() == 1) {
					return_value = que_b.front();
					que_b.pop();
					break;
				}
				que_a.push(que_b.front());
				que_b.pop();
			}
		}
		using_que_a = !using_que_a;
		return return_value;
	}

	/** Get the top element. */
	int top() {
		int return_value;
		if (this->using_que_a) {
			while (!que_a.empty()) {
				if (que_a.size() == 1)
					return_value = que_a.front();
				que_b.push(que_a.front());
				que_a.pop();
			}
		}
		else {
			while (!que_b.empty()) {
				if (que_b.size() == 1)
					return_value = que_b.front();
				que_a.push(que_b.front());
				que_b.pop();
			}
		}
		using_que_a = !using_que_a;
		return return_value;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return using_que_a ? que_a.size() == 0 : que_b.size() == 0;
	}

private:
	queue<int> que_a, que_b;
	bool using_que_a;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
