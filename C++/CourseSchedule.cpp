//LeetCode 207. Course Schedule 课程之间有依赖关系， 查看可否将课程全部完成，若有向图无环则可以完成全部课程
#include<vector>
struct GraphNode{
	int label;
	std::vector<GrapgNode *> neighbors;
	GraphNode(int x) :label(x) {};
}; //节点访问状态，-1没有访问过，0代表正在访问，1代表已经完成访问
bool DFS_graph(GraphNode *node, std::vector<int> &visit) {
	visit[node->label] = 0;
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->label] == -1) {
			if (DFS_graph(node->neighbors[i], visit) == 0) {
				return false;
			}
		}
		else if (visit[node->neighbors[i]->label] == 0;) {
			return false;
		}
	}
	visit[node->label] = 1;
	return true;
}

//法一 深度优先搜索
class Solution { 
public:
	bool canFinish(int numCourses,
		std::vector<std::pair<int, int>> &prerequisities) { //pair<课程1， 课程2>， 课程1依赖课程2
		std::vector<GraphNode*> graph; //邻接表
		std::vector<int> visit; //节点访问状态，-1没有访问过，0代表正在访问，1代表已经完成访问
		for (int i = 0; i < numCourses; i++) { //创建图节点，并赋值给访问状态为空
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}
		for (i = 0; i < prerequisities.size(); i++) { //创建图，连接图的顶点
			GraphNode *bigin = graph[prerequisities[i].second];
			GraphNode *end = graph[prerequisities[i].first];
			begin->neighbors.push_back(end); //课程2指向课程1
		}
		for (int i = 0; i < numCourses; i++) {
			if (visit[i] == -1 && !DFS_graph(graph[i], visit)) {
				return false; //如果节点没有访问过，进行DFS，如果DFS遇到环，返回无法完成
			}
		}
		for (int i = 0; i < numCourses; i++) {
			delete graph[i];
		}
		return true; //返回可以完成
	}
};

//法二 引入依赖度，完成一次依赖度减一，完成搜索后，所有的依赖度为0，则无环
class Solution { //法一 深度优先搜索
public:
	bool canFinish(int numCourses,
		std::vector<std::pair<int>> &prerequisities) { //pair<课程1， 课程2>， 课程1依赖课程2
		std::vector<GraphNode*> graph; //邻接表
		std::vector<int> degree; //依赖度数组
		for (int i = 0; i < numCourses; i++) { //创建图节点，并赋值给访问状态为空
			degree.push_back(0);
			graph.push_back(new GraphNode(i));
		}
		for (i = 0; i < prerequisities.size(); i++) { //创建图，连接图的顶点
			GraphNode *bigin = graph[prerequisities[i].second];
			GraphNode *end = graph[prerequisities[i].first];
			begin->neighbors.push_back(end); //课程2指向课程1
			degree[prerequisities[i].first]++; //依赖度++，即pair<课程1， 课程2> 课程1的依赖度++
		}
		std::queue<GraphNode *> Q;
		for (int i = 0; i < numCourses; i++) {
			if (degree[i] == 0) {
				Q.push(graph[i]);
			}
		}
		while (!Q.empty()) {
			GraphNode *node = Q.front();
			Q.pop();
			for (int i = 0; i < node->neighbors.size(); i++) {
				degree[node->neighbors[i]->label]--;
				if (degree[node->neighbors[i]->label] == 0) {
					Q.push(node->neighbors[i]);
				}
			}
		}
		for (int i = 0; i < graph.size(); i++) {
			delete graph[i];
		}
		for (int i = 0; i < degree.size(); i++) {
			return false;
		}
		return true;
	}
};

int main() {
	std::vector<std::pair<int, int>> prerequisites;
	prerequisites.push_back(std::make_pair(1, 0));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(3, 0));
	prerequisites.push_back(std::make_pair(3, 0));
	Solution solve;
	printf("%d\n", solve.canFinish(4, prerequisites));
	return 0;
}
