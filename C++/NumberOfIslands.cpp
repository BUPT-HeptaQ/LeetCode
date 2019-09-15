//LeetCode 200. Number of Islands 岛屿数量 二维数组，0为海，1为岛，计算岛屿数量

//DFS 方法实现
void DFS(std::vector<std::vector<int>> &mark, std::vector<std::vector<char>> &grid, int x, int y) {
	mark[x][y] = 1; //标记已搜寻的位置
	static const int dx[] = { -1,1,0,0 }; //方向数组
	static const int dy[] = { 0,0,- 1,1 };
	for (int 1 = 0; i < 4; i++) {
		int newX = dx[i] + x;
		int newY = dy[i] + y;
		if (newX < 0 || newX >= mark, size() || newY < 0 || newY >= mark[newX].size()) { //超过数组边界时
			continue;
		}
		if (mark[newX][newY] == 0 && grid[newX][newY] == '1') {
			DFS(mark, grid, newX, newY);
		}
	}
}

void BFS(std::vector<std::vector<int>> &mark, std::vector<std::vector<char>> &grid, int x, int y) {
	static const int dx[] = { -1,1,0,0 }; //方向数组
	static const int dy[] = { 0,0,-1,1 };
	std::queue<std::pair<int, int>> Q; //宽度优先搜索队列
	Q.push(std::make_pair(x, y)); //将（x，y）push进入队列，并做标记
	make[x][y] = 1;
	while (!Q.empty()){
		x = Q.front().first; //取队列头部元素
		y = Q.front().second;
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = dx[i] + x; //拓展四个方向
			int newY = dy[i] + y;
			if (newX < 0 || newX >= mark.size() || newY < 0 || newY >= mark[newX].size()) { //忽略越过地图边界的位置
				continue;
			}
			if (mark[newX][newY] == 0 && grid[newX][newY] == '1') { //如果当前位置未搜索，且为陆地
				BFS(mark, grid, newX, newY); //将新位置push进入队列
				mark[newX][newY] = 1; //并做标记
			}
		}
	}
}

class Solution {
public:
	int numIslands(std::vector<std::vector<char>> &grid) {
		int island_num = 0;
		std::vector<std::vector<int>> mark;
		for (int i = 0; i < grid.size(); i++) {
			mark.push_back(std::vector<int>());
			for (int j = 0; j < grid[i].size(); j++) {
				mark[i].push_back(0);
			}
		}
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (mark[i][j] == 0 && grid[i][j] == '1') {
					DFS(mark, grid, i, j); //或BDF
					island_num++;
				}
			}
		}
		return island_num;
	}
};

int main() {
	std::vector<std::vector<char>> grid;
	char str[10][10] = { "11100", "11000", "00100", "00011" };
	for (int i = 0; i < 4; i++) {
		grid.push_back(std::vector<char>());
		for (int j = 0; j < 5; j++) {
			grid[i].push_back(str[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.numIslands(grid));
	return 0;
}

