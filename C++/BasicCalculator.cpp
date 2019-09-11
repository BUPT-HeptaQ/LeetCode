// 5. leetcode 224 basic calculator (only have + and -)
#include <string>
#include <stack>

class Solution {
public:
	int calculator(std::string s) {
		static const int STATE_BEGIN = 0;
		static const int NUMBER_STATE = 1;
		static const int OPERATION_STATE = 2;
		std::stack <int> number_stack;
		std::stack <char> operation_stack;
		int number = 0;
		int STATE = STATE_BEGIN;
		int compuate_flag = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				continue;
			}
			swith(STATE) {
			case STATE_BEGIN:
				if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
				}
				else {
					STATE = OPERATION_STATE;
					i--;
				}
				break;

			case NUMBER_STATE:
				if (s[i] >= '0' && s[i] <= '9') {
					number = number * 10 + s[i] - '0';
				}
				else {
					number_stack.push(number);
					if (compile_flag == 1) {
						compuate(number_stack, operation_stack);
					}
					number = 0;
					i--;
					STATE = OPERATION_STATE;
				}
				break;
			case OPERATION_STATE:
				if (s[i] == '+' || s[i] == '-') {
					operation_stack.push(s[i]);
					compuate_flag = 1;
				}
				else if (s[i] == '(') {
					STATE = NUMBER_STATE;
					compuate_flag = 0;
				}
				else if (s[i] >= '0' && s[i] <= '9') {
					STATE = NUMBER_STATE;
					i--;
				}
				else if (s[i] == ')') {
					compute(number_stack, operation_stack);
				}
				break;
			}	
		}
		if (number != 0) {
			number_stack.push(number);
			compute(number_stack, operation_stack);
		}
		if (number == 0 && number_stack.empty()) {
			return 0;
		}
		return number_stack.top();
	}
};
