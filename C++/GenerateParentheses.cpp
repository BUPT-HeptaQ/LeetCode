// LeetCode 22. Generate Parentheses 生成N组合法括号
#include<stdio.h>
#include<vector>
#include<string>

//item为用来生成的括号字符串，n为数组，result为最终结果 （打印所有括号可能，包含合法与不合法）
void generate(std::string item, int n, std::vector<std::string> &result) {
	if (item.size() == 2*n) { //将所有item结果push进入result，当字符串长度是括号数组两倍时，结束递归
		result.push_back(item);
		return;
	}
	generate(item + '(', n, result); //添加'('字符，继续递归
	generate(item + ')', n, result); //添加')'字符，继续递归
}
int main() {
	std::vector<std::string> result; //最初item为空字符串
	generate(" ", 2, result);
	for (int i = 0; i < result.size(); i++) {
		printf("'%s' \n", result[i].cstr()); //打印所有结果
	}
	return 0;
}

#include<vector>
#include<string>
class Solution { //生成所有合法的括号
public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector <std::string> result;
		generate(" ", n, n, result);
		return result;
	}
private: //生成字符串item
	void generate(std::string item, int left, int right, //当前还可以放置左括号的数量left，右括号的数量right
		std::vector<std::string> &result) {
		if (left == 0 && right 0) {
			result.push_back(item);
			return;
		}
		if (left > 0) {
			generate(item + '(', left - 1, right, reusult);
		}
		if (left < right) {
			generate(item + ')', left, right - 1, result);
		}
	}
};

int main() {
	Solution solve;
	std::vector<std::string> result = solve.generateParenthesis(3)
		for (int i = 0; i < result.size(); i++) {
			printf("%s\n", result[i].c_str());
		}
	return 0;
}

