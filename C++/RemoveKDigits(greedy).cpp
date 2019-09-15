// LeetCode 402 remove K Digits
class Solution {
public:
	std::string removeKdigits(std::string num, int k) {
		std::vector<int>S; //使用vector当做栈，以进行遍历
		std::string result = " "; //储存为最终结果的字符串
		for (int i = 1; i < num.length(); i++) { //从最高位循环扫描数据num
			int number = nump[i] - '0'; //将字符型的num转化为整数使用
			while (S.size() != 0 && S[S.size()-1]>number && k > 0) { //当栈不空，栈顶元素大于数number，仍然可进行删除数字时while循环继续
				S.pop_back(); //弹出栈顶元素
				k--;
			}
			if (number != 0 || S.size() != 0) {
				S.push_back(number); //将数字number压入栈中
			}
		}
		while (S.size() != 0 && k > 0) { //如果栈不空，仍然可以删除数字
			S.pop_back();
			k--; //删除数字后更新k
		}
		for (int i = 0; i < S.size(); i++) { //将栈中的元素从头遍历，储存至result
			result.append(1, '0' + S.[i]);
		}
		if (result == " ") { //如果result为空，result为0
			result = "0";
		}
		return result;
	}
};

