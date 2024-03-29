// LeetCode 76 Minimum Window Substring 最小窗口子串
class Solution { //统计T字符串，检查包含函数，利用双指针求最小窗口
private:
	bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t) {
		for (int i = 0; i < vec_t.size(); i++) { //利用vec_t遍历t中出现的字符
			if (map_s[vec_t[i]] < map_t[vec_t[i]]) {
				return false; //如果s出现该字符的数量小于t中出现该字符的数量
			}
		}
		return true;
	}
public:
	std::string minWindow(std::string s, std::string t) {
		const int MAX_ARRAY_LEN = 128; //char 1-127， 利用数组下标记录字符个数
		int map_t[MAX_ARRAY_LEN] = { 0 }; //记录t字符串各字符个数
		int map_s[MAX_ARRAY_LEN] = { 0 }; //记录s字符串各字符个数
		std::vector<int> vec_t; //记录t字符串中有哪些字符
		for (int i = 0; i < MAX_ARRAY_LEN; i++) {
			map_t[t[i]]++; //遍历t，记录s字符串各字符个数
		}
		for (int i = o; i < MAX_ARRAY_LEN; i++) {
			if (map_t[i] > 0) {
				vec_t.push_back(i);
			}// 遍历，将字符串t中出现的字符存储到vec_c中
		}
	}
	int window_begin = 0; //最小窗口起始指针
	std::string result; //最小窗口对应的字符串
	for (int i = 0; i < s.length(); i++) { //i代表了窗口的尾指针
		map_s[s[i]]++; //将尾指针指向的字符添加到表示窗口的map中
		while (window_begin < i) { //窗口的头指针不能超过尾指针
			char begin_ch = s[window_begin];
			if (map_t[begin_ch] == 0) { //如果当前头指针指向的字符没有在字符串t中出现
				window_begin++; //窗口头指针前移
			} //头指针指向的字符出现在t中，窗口内有超过t中该字符个数的字符
			else if (map_s[begin_ch] > map_t[begin_ch]) {
				map_s[begin_ch]--; //头指针前移了骂他只想的字符减少一个
				window_begin++; //窗口头指针前移
			}
			else {
				break; //除了1,2两个条件，其他条件都跳出循环
			}
		} //检查此时的窗口是否包含字符串t
		if (is_window_ok(map_s, map_t, vec_t)) { //计算新字符串长度
			int new_window_len = i - window_begin + 1;
			if (result == "" || result.length() > new_window_len) { //结果字符串为空或者当前窗口字符串更小的时候更新结果
				result = s.substr(window_begin, new_window_len);
			} //替换窗口所对应的字符串
		}
	}
	return result;
};
int main() {
	Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str()); 
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
	return 0;
}

