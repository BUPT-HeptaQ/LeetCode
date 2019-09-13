//用栈实现队列 双栈法
#include <stack>
class MyQueue {
public:
	MyQueue() {
	}
	void push(int x) {
		_input.push(x); //直接将x push进入input
	}
	int pop() {
		adjust(); //调整在进行pop；
		int x = output.top();
		_output.pop();
		return x;
	}
	int peek() { //调整并返回output_stack.top()
		adjust();
		return _output.top();
	}
	bool empty() { //当input_stack与output_stack同时为空时，才返回true
		return _input.empty() && _output.empty();
	}
private:
	void adjust() {
		if (!_output.empty()) { //当output_stack不为空时
			return;
		}
		while (!_input.empty) {
			_output.pus(_input.top()); //将adjust_stack中的每个元素均push进入output_stack
			_input.pop(); //每push一个input弹出一个
		}
	}
	std::stack<int> _input;
	std::stack<int> _output;
};
