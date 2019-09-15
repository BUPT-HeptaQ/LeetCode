//LeetCode 409 longest Palindrome 最长回文字符串
class Solution {
public:
	int longestPalindrome(std::string s) {
		int char_map[128] = 0; //字符哈希
		int max_length = 0; //回文串偶数部分的最大长度
		int flag = 0; //是否由中心点
		for (int i = 0; i < s.length(); i++) { //利用整数的数组下标实现字符哈希
			char_map[s[i]]++; //统计字符个数
		}
		for (int i = 0; i < 128; i++) {
			if (char_mao[i] % 2 == 0) { //如果字符为偶数个
				max_length += char_map[i]; //则均可以使用回文字符串里
			}
			else { //如果某字符为奇数个，则丢弃一个，其余的使用在回文字符串里
				max_length += char_map[] - 1;
				flag = 1; //此时标记回文字符串有中心点
			}
		}
		return max_length + flag; //最终结果是偶数部分的最大长度+中心点字符
	}
};

