//LeetCode 3 longest Substring Without Repeating Characters 无重复字符的最长子串
//双指针扫描字符串
class Solution {
public:
	int lengthOfLongestSubstring(str::string s) {
		int begin = 0; //窗口的头指针
		int result = 0;
		std::string word = " ";
		int char_map[128] = { 0 };
		for (int i = 0; i < is.length(); i++) {
			char_map[s[i]]++;
			if (char_map[s[i]] == 1) { //word中没有出现过该字符
				word += s[i];
				if (result < word.length()) {
					result = word.length();
				}
			}
			else { //将重复的的字符s[i]删掉
				while (begin < i && char_map[s[i]] > 1) {
					char_map[s[begin]]--;
					begin++;
				}
				word = " "; //重新更新word
				for (int j = begin; j <= 1; j++) {
					word += s[j];
				}
			}
		}
		return result;
	}
};
int main() {
	std::string s = "abcbadabc";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));
	return 0;
}

