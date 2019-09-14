/LeetCode 114.Flatten Binary Tree to Linked List
//法一 前序遍历，就地转换

#include<vector>
class Solution {
public:
	void flatten(TreeNode *root) {
		std::vector<TreeNode *> node_vec;
		preorder(root, node_vec);
		for (int i = 1; i < node_vec.size(); i++) {
			node_vec[i - 1]->left = NULL;
			node_vec[i - 1]->right = node_vec[i];
		}
	}
private:
	void preorder(TreeNode *node, std::vector<TreeNode*> &node_vec) {
		if (!node) {
			return;
		}
		node_vec.push_back(node);
		preorder(node->left, node_vec);
		preorder(node->right, node_vec);
	}
};

//法二 将以node为根的树转为链表（拉直），并传出必要信息
class Solution {
public:
	void flatten(TreeNode *root) {
		TreeNode* last = NULL;
		preorder(root, last);
	}
private:
	void preorder(TreeNode *node, TreeNode *&last) { //node:当前节点
		if (!node) { //last当前子树的先序遍历的最后一个节点，传引用会传出
			return;
		}
		if (!node->left && !node->right) {
			last = node;
			return;
		}
		TreeNode *left = node->left;
		TreeNode *right = node->right; //备份左右节点
		TreeNode *left_last = NULL;
		TreeNode *right_last = NULL; //左右子树最后一个节点
		if (left) {
			preorder(left, left_last); //若有左子树，递归将左子树转换为单链表
			node->left = NULL; //左指针赋空值
			node->right = left;
			last = left_last; //将该节点的last保存为左子树的last
		}
		if (right) { //若有右子树，递归将右子树转换为单链表
			preorder(right, right_last); //若node找到左子树最后一个节点（有左子树）
			if (left_last) {
				left_last->right = right;
			}
			last = right_last;
		}
	}
};
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
	c.left = &f;

	Solution solve;
	solve.flatten(&a);
	TreeNode *head = &a;
	while (head) {
		if (head->left) {
			printf("ERROR \n");
		}
		printf("[%d]", head->val);
		head = head->right;
	}
	printf("\n");
	return 0;
}

