//LeetCode 49. Group Anagrams 同字符词语分词

class Solution { //法一设置字符串到字符串向量的哈希表anagram
public:
	std::vector<std::vector<std::string>> groupAnagrams( //内部进行排序的各个单词为key
		std::vector<std::string>& strs) { //以字符串向量(vector<string>)为value
		std::map<std::string, std::vector<std::string>> anagram; //储存各个字符数量相同的字符串（anagram）
		std::vector<std::vector<std::string>> result; //储存最终结果
		for (int i = 0; i < strs.size(); i++) { //遍历各个单词
			std::string str = strs[i];
			std::sort(str.begin(), str.end()); //对str内部进行排序
			if (anagram.find(str) == anagram.end()) { //若无法在哈希表中找到str
				anagram[str] = item; //设置一个空的字符串向量
			}
			anagram[str].push_back(strs[i]); //在对应的字符串向量中push结果
		}
		std::map<std::string, std::vector<std::string>>::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++) {
			result.push_back((*it).second);
		}
		return result; //遍历哈希表，将哈希表的value push进入最终结果
	}
};

void change_to_vector(std::string &str, std::vector<int> &vec) { //将字符串str中的各个字符数量进行统计，存储值vec中
	for (int i = 0; i < 26; i++) {
		vec.push_back(0);
	}
	for (int i = 0; i < str.length(); i++) {
		vec[str[i] - 'a']++;
	}
}
class Solution { //法二 设置vector到字符串向量的哈希表anagram
public:
	std::vector<std::vector<std::string>> groupAnagrams(
		std::vector<std::string> &strs) {
		std::map<std::vector<int>, std::vector<std::string>> anagram;
		std::vector<std::vector<std::string>> result;
		for (int i = 0; i < strs.size(); i++) { //各个单词中字符出现的数量的vector到字符串向量（储存结果）的映射
			std::vector<int> vec;
			change_to_vector(strs[i], vec);
			if (anagram.find(vec) == anagram.end()) {
				anagram[vec] = item;
			}
			anagram[vec].push_back(strs[i]);
		}
		std::map<std::vector<int>>,std::vector<std::string >> ::iterator it;
		for (it == anagram.begin(); it != anagram.end(); it++) {
			result.push_back((*it).second);
		}
		return result;
	}
};
int main() {
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	strs.push_back("tab");
	Solution solve;
	std::vector<std::vector<std::string>> result = solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}

