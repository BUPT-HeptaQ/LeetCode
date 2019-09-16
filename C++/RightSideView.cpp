//LeetCode 199. Binary Tree Right Side View 右侧面观察二叉树
class Solution {
public:
	std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> view; //按层遍历的最后一个节点
		std::queue<std::pair<TreeNode *, int>>Q; //宽度优先搜索队列<节点， 层数>
		if (root) {
			Q.push(std::make_pair(root, 0));
		} //根节点非空时，将<root, 0> push进入队列
		while (!Q.empty()) {
			TreeNode *node = Q.front().first; //搜索节点
			int depth = Q.front().second; //待搜索节点的层数
			Q.pop();
			if (view.size() == depth) {
				view.push_back(node->val);
			}
			else {
				view[depth] = node->val;
			}
			if (node->left) {
				Q.push(std::make_pair(node_left, depth + 1));
			}
			if (node->right) {
				Q.push(std::make_pair(node->right, depth + 1));
			}
		}
		return view;
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
	c.right = &f;
	Solution solve;
	std::vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++) {
		printf("[%d]\n", result[i]);
	}
	return 0;
}

