// LeetCode 225 用队列实现栈
#include <queue>
class MyStack { //临时队列，利用该队列进行原始
public:
	MyStack() {// 与新元素的次序对调
	}
	void push(int x) {
		std::queue<int> tem_queue;
		temp_queue.push(x); //对于新元素x的操作
		while (!_data.empty()) { //只要_data数据队列不为空，即开始循环
			temp_queue.push(_data.front()); 
			_data.pop();
		}
		while (!temp_queue.empty()) { //只要临时队列temp_queue不为空即循环
			_data.push(temp_queue.front());
			temp_queue.pop();
		} //pop 弹出栈顶并返回栈顶元素
	}
	int pop() {
		int x = _data.front(); //取栈顶元素，即为队列头部元素
		_data.pop(); //弹出队列头部元素
		return x; //返回取出的队列头部元素想，即为栈顶元素
	}
	int top() {
		return _data.front();
	}
	bool empty() {
		return _data.empty();
	}
private:
	std::queue<int> _data; //_data数据队列存储元素的顺序就是栈储存元素的顺序
};

