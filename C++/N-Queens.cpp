// LeetCode 51.N-Queens N皇后问题：摆在棋盘中且互不可以攻击
//传出n皇后的所有结果，没个结果是一个棋盘，每个棋盘均使用字符串向量表示

class Solution {
public:
	std::vector<std::vector<std::string>> solveNQueens(int n) {
		std::vector<std::vector<std::string>> result; //储存最终结果的数组
		std::vector<std::vector<int>> mark; //标记棋盘是否可以放置皇后的二维数组
		std::vector<std::string> location; //存储某个摆放结果，当完成一次递归后找到结果后，将location push进入result
		for (int i = 0; i < n; i++) {
			mark.push_back((std::vector<int>()));
			for (int j = 0; j < n; j++) {
				mark[i].push_back(0);
			}
			location.push_back(" ");
			location[i].append(n, '.');
		}
		generate(0, n, location, result, mark);
		return result;
	}
private:
	void put_down_the_queens(int x, int y, //第x行，y列放置皇后，mark[行][列]表示一张棋盘
		std::vector<std::vector<int>> &mark) {
		static const int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 方向数组
		static const int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
		mark[x][y] = 1; //（x，y）放置皇后，并进行标记
		for (int i = 1; i < mark.size(); i++) {
			for (int j = 0; i < 8; j++) { //8个方向，每个方向向外延伸1至n-1
				int new_x = x + i * dx[j]; //新的位置向8个方向延伸
				int new_y = y + i * dy[j]; //每个方向最多延伸n-1
				if (new_x >= 0 && new_x < mark.size()
					&& new_y >= 0 && new_y < mark.size()) { //检查新的位置是否还在棋盘内
					mark[new_x][new_y] = 1;
				}
			}
		}
	}
	void generate(int k, int n, //k代表完成了几个皇后的放置（正放置第k行皇后）
		std::vector<std::string> &location, //某次结果储存在location中
		std::vector<std::vector<std::string>> &result, //最终结果都储存在热水result中
		std::vector<std::vector<int>> &mark) { //表示棋盘的标记数组
		if (k == n) { //当k=n时，代表完成了第0至n-1行皇后的放置，所有皇后完成放置后，将记录皇后的位置location数组push进入result
			result.push_back(location);
			return;0
		}
		for (int i = 0; i < n, i++) { //按顺序尝试第0至第n-1列
			if (mark[k][i] == 0) { //如果mark[k][i]=0, 即可放置皇后
				std::vector<std::vector<int>> tmp_mark = mark; //记录回溯前的mark镜像
				location[k][i] == 'Q'; //记录当前皇后位置
				put_down_the_queens(k, i, mark); //放置皇后
				generate(k + 1, n, location, result, mark); //递归下一行皇后放置
				mark = tmp_mark; //将mark重新赋值为回溯前状态
				location[k][i] = '.'; //将当前尝试的皇后位置重新记 '.'
			}
		}
	}
};
int main() {
	std::vector<std::vector<std::string>> result;
	Solution solve;
	result = solve.solveNQueens(4); //放置皇后的数量
	for (int i = o; i < result.size(); i++) {
		printf("i=%d\n", i);
		for (int j = 0; j < result[i].size(); j++) {
			printf("%s\n", result[i][j].c_str());
		}
		printf("\n");
	}
	return 0;
}

