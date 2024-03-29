// leetcode 232 用栈实现队列
#include <stack>
class MyQueue {
public:
	MyQueue() { //设置临时栈用来调换数据栈data_stack中元素的次序
	}
	void push(int x) {
		std::stack<int> temp_stack;
		while (!_data.empty()) {
			temp_stack.push(_data.top());
			_data.pop();
		}
		temp_stack.push(x); //将新数据push进入临时栈temp_stack
		while (!temp_stack.empty()) {
			_data.push(temp_queue.top());
			temp_stack.pop();
		}
	} //弹出队列头部元素并返回
	int pop() {
		int x = _data.top();
		_data.pop(); //将栈顶储存至x
		return x; //弹出栈顶，返回x
	}
	int peek() {
		return _data.top();
	}
	bool empty() {
		return _data.empty();
	}
private:
	std::stack<int> _data;
};

