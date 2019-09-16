//LeetCode 290. Word Pattern 词语模式，确认str和pattern是否匹配
class Solution {
public:
	bool wordPattern(std::string pattern, std::string str) {
		std::map<std::string, char> word_map; //单词到pattern字符的映射
		char used[128] = { 0 }; //已被映射出的pattern字符
		std::string word; //临时保存拆分出的单词
		int pos = 0; //当前指向的pattern字符 （无需处理最后一个单词）
		str.push_back(' '); //str尾部push一个空格，使得遇到空格拆分单词
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') { //遇到空格，即拆分出一个新的单词
				if (pos == pattern.length()) { //若分隔出一个单词，但已无pattern字符对应
					return false;
				} //若单词未出现在哈希映射中
				if (word_map.find(word) == word_map.end()) {
					if (used[pattern[pos]]) { //如果当pattern字符已经使用
						return false;
					}
					word_map[word] = pattern[pos];
					used[pattern[pos]] = 1;
				}
				else {
					if (word_map[word] != pattern[pos]) { //若当前word已建立映射无法与当前pattern对应
						return false;
					}
				}
				word = " "; //完成一个单词的插入和查询后，清空word
				pos++; //指向pattern字符的pos指针前移
			}
			else {
				word += str[i];
			}
		}
		if (pos != pattern.length()) {
			return false; //有多余的pattern字符
		}
		return ture;
	}
};

int main() {
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
	return 0;
}

