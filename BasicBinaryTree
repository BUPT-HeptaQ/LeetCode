// 二叉树的基本构造
#include<stdio.h>
struct TreeNode { //二叉树数据结构
	int val; //数据域val
	TreeNode *left;
	TreeNode *right; //left，right左右子树指针
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

void preoder_print(TreeNode *node, int layer) { //正在遍历的节点和当前节点的层数
	if (!node) {
		return;
	}
	for (int i = 0; i < layer; i++) {
		printf("----") //根据层数，打印相应的'-'
	}
	printf("[%d]\n", node->val);
	preoder_print(node->left, layer + 1); //遍历左子树，层数+1
	preoder_print(node->right, layer + 1); //遍历右子树，层数+1
}
int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	preoder_print(&a, 0);
	return 0;
}
