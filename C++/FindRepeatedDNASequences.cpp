//LeetCode 187 Repeated DNA Sequences 重复的DNA序列
class Solution {
public:
	std::vector<std::string> findRepeatedDnaSequences(std::string s) {
		std::map<std::string, int>  word_map; //<单词， 单词数量>的映射
		std::vector<std::string> result;
		for (int i = 0; i < s.length(); i++) { //若word在映射中出现
			std::string word = s.substr(i, 10);
			if (word_map.find(word) != word_map.end()) {
				word_map[word] += 1;
			}
			else {
				word_map[word] = 1;
			}
		}
		std::map<std::string, int>::_Deque_const_iterator it; //遍历哈希表中的所有单词
		for (it = word_map.begin(); it != word_map.end(); it++) {
			if (it->second > 1) {
				result.push_back(it->first);
			}
		}
		return result;
	}
};

//法二 位运算法，吧ACGT转化为四进制

int g_hash_map[1048576] = { 0 }; //哈希太大了，需要全局数组，会占用虚拟内存，不会爆本机内存，需要考虑底层操作系统

std::string change_int_to_DNA(int DNA) {
	static const char DNA_CHAR[] = { 'A', 'C', 'G', 'T' };
	std::streambuf str;
	for (int i = 0; i < 10; i++) { //讲一个长度为10的片段，从整数转为字符串
		str += DNA_CHAR[DNA & 3];
		DNA = DNA >> 2;
	}
	return str;
}
class Solution {
public:
	std::vector<std::string> findRepeatedDnaSequences(std::string s) {
		std::vector<std::string> result;
		if (s.length() < 10) {
			return result;
		}
		for (int i = 0; i < 1048576; i++) { //每次调用时需要更新全局变量
			g_hash_map[i] = 0;
		}
		int char_map[128] = { 0 };
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3; //设置字符到整数的转换数组
		int key = 0;
		for (int i = 9; i >= 0; i--) { //将DNA字符串的前10个字符
			key = (ket << 2) + char_map[s[i]];
		}
		g_hash_map[key] = 1;
		for (int i = 10; i < s.length(); i++) {
			key = key >> 2;
			key = key | (char_map[s[i]] << 18);
			g_hash_map[key]++;
		}
		for (int i = 0; i < 1048576; i++) {
			if (g_hash_map[i] > 1) {
				result.push_back(change_int_to_DNA(i));
			}
		} //将出现次数大于2的片段push进入结果
		return result;
	}
};

int main() {
	std::string s = "AAAAACCCCCAAAAACCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++) {
		printf("%s\n", result[i].c_str());
	}
	return 0;
}

