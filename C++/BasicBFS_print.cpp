//基础二叉树层次遍历数据结构
#include<stdio.h>
#include<vector>
#include<queue>

struct TreeNode { //二叉树数据结构
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
void BFS_print(TreeNode *root) { // 宽度优先搜索二叉树
	std; :queue<TreeNode*>Q;
	Q.push(root);
	while (!Q.empty()) {
		TreeNode *node = Q.front();
		Q.pop();
		printf("[%d]\n", node->val);
		if (node->left) {
			Q.push(node->left);
		}
		if (node->right) {
			Q.push(node->right); 
		}
	}
}
int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	BFS_print(&a);
	return 0;
}
