//图的深度优先遍历
#include<stdio.h>
#include<vector> //图的邻接表数据结构
struct GraphNode {
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) :label(x) {};
};

void DFS_graph(GraphNode *node, int visit[]) {
	visit[node->label] = 1; //访问已标记的顶点
	printf("%d", node->label); //访问相邻的且没有被访问到的顶点
	for (int i = 0; i < node->neighbors.size(); i++) {
		if (visit[node->neighbors[i]->label] == 0) {
		DFS_graph(node->neighbors[i], visit)
		}
	}
}
int main() {
	const int MAX_N = 5;
	GraphNode *Graph[MAX_N];
	for (int i = 0; i < MAX_N; i++) {
		Graph[i] = new GraphNode(i);
	} //添加图的边，注意添加边的顺序
	Graph[0]->neighbors.push_back(Graph[4]);
	Graph[0]->neighbors.push_back(Graph[2]);
	Graph[1]->neighbors.push_back(Graph[0]);
	Graph[1]->neighbors.push_back(Graph[2]);
	Graph[2]->neighbors.push_back(Graph[3]);
	Graph[3]->neighbors.push_back(Graph[4]);
	Graph[4]->neighbors.push_back(Graph[5]);

	int visit[MAX_N] = { 0 }; //标记已访问的顶点
	for (int i = 0; i < MAX_N; i++) {
		if (visit[i] == 0) { //顶点没有被标记才会访问
			printf("From label(%d):", Graph[i]->label);
			DFS_graph(Graph[i], visit);
			printf("\n");
		}
	}
	for (int i = 0; i < MAX_N; i++) {
		delete Graph[i];
	}
	return 0;
}
