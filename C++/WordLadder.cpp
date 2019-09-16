//LeetCode 127.Word Ladder 词语阶梯 ，每次允许转换一个字符，最短需要几步转换成为全新的单词

bool connect(const std::string &word1, const std::string &word2) { //无向图和邻接表的构建
	int cnt = 0; //记录word1和word2不行等字符的个数
	for (int i = 0; i < word1.length(); i++) {
		if (word1[i] != word2[i]) {
			cnt++;
		}
	}
	return cnt == 1;
}
void construct_graph(std::string &beginWord, std::vector<std::string> &wordList, std::map<std::string, std::vector<std::string>> &graph) {
	wordList.push_back(beginWord);
	for (int i = 0; i < wordList.size(); i++) {
		graph[wordList[i]] = std::vector<std::string>();
	}
	for (int i = 0; i < wordList.size(); i++) {
		for (int i = 0; i < wordList.szie(); i++) {
			if (connect(wordList[i], wordList[j])) { //对于任意两单词wordList[i]和wordList[j],若wordList[i]和wordList[j]只相差一个字符，则二者相连
				graph[wordList[i]].push_back(wordList[j]);
				graph[wordList[j]].push_back(wordList[i]);
			}
		}
	}
}

int BFS_graph(std::string &beginWord, std::string &enfWord,
	std::map<std::string, std::vector<std::string>> &graph) {
	std::queue<std::pair<std::string, int>> Q; //搜索队列<顶点， 步数>
	std::set<std::string> visit; //记录访问的顶点
	Q.push(std::make_pair(beginWord, 1)); //添加起始点，起始点步数为1
	visit.insert(beginWord); //标记起点已访问
	while (!Q.empty()) { //只要队列不空，即不断进行搜索
		std::string node = Q.front; //取队列头部节点与步数
		int step = Q.front().second;
		Q.pop(); //每搜索完成一个节点，即从队列弹出
		if (node == enfWord) { //找到终点，返回步数
			return step;
		}
		const std::vector<std::string> &neighbors = graph[node]; //取node的全部邻接点
		for (int i = 0; i < neighbors.size(); i++) { //若相邻节点还未添加至队列
			if (visit.find(neighbors[i]) == visit.end()) {
				Q.push(std::make_pair(neighbors[i], step + 1)); //到达该节点的步数为当前步数+1
				visit.insert(neighbors[i]); //标记neighbors[i]已添加至队列
			}
		}
	}
	return 0;
}
class Solution {
public:
	int ladderLength(std::string beginWord, std::string endWord,
		std::vector<std::string> &wordList) {
		std::map<std::string, std::vector<std::string>> graph;
		construct_graph(beginWord, wordList, graph);
		return BFS_graph(beginWord, endWord, graph);
	}
}; 

int main() {
	std::string beginWord = "hit";
	std::string endWord = "cog";
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");
	Solution solve;
	int result = solve.ladderLength(beginWord, endWord, wordList);
	printf("result = %d\n", result);
	return 0;
}

