//判断出入栈顺序是否合法
#include<stack>
#include<queue>

bool check_is_vaild_order(std::queue<int> &order) { //检查队列（储存在队列中）
	std::stack<int>S; //S为模拟栈
	int n = order.size(); //n为序列长度，将1-n按顺序入栈
	for (int i = 1; i <= n; i++) {
		S.push(i); //元素i入栈
		while (!S.empty() && order.front() == S.top) {
			S.pop();
			order.pop)();
		}
	}
	if (!S.empty()) {
		return false;
	}
	return true;
}

