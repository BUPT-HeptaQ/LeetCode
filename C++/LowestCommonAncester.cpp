//LeetCode 236. Lowest Common Ancester of a Binary Tree 最近公共祖先
//在公共路径上最后一个相同的节点

//求根节点至某节点的路径
void preorder(TreeNode* node, //正在遍历的节点
	TreeNode *search, //带搜索的节点
	std::vector<TreeNode*> &path, //遍历时的节点路径栈
	std::vector<TreeNode*> &result, //最终搜索到节点search的路径结果
	int &finish) { //记录是否找到节点search的变量，未找到时是0，找到是1
	if (!node || finish) { //当node为空或已找到search节点直接返回，结束搜索
		return;
	}
	path.push_back(node); //先序遍历，将节点压入path栈
	if (node == search) { //当找到search节点后，标记finish变量
		finish = 1;
		result = path; //将当前节点的path存储到result中
	}
	preorder(node->left, search, path, result, finish); //深度遍历node左孩子
	preorder(node->right, search, path, result, finish); //深度遍历node右孩子
	path.pop_back(); //结束遍历node，将node节点弹出path栈
}

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		std::vector<TreeNode*> path; //声明遍历用的临时栈
		std::vector<TreeNode*> node_p_path; //储存p节点路径
		std::vector<TreeNode*> node_q_path; //储存q节点路径
		int finish = 0; //记录是否完成搜索的变量finish
		preorder(root, p, path, node_p_path, finish);
		path.clear();
		finish = 0; //清空path，finish，计算q节点路径
		preorder(root, q, path, node_q_path, finish);
		int path_len = 0; //较短路径的长度
		if (node_p_path.size() < node_q_path.size()) {
			path_len = node_p_path.size();
		}
		else {
			path_len = node_p_path.size();
		}
		TreeNode *result = 0; //同时遍历根到p，q两节点的路径上的节点
		for (int i = 0; i < path_len; i++) {
			if (node_p_path[i] == node_q_path[i]) {
				result = node_p_path[i]; //找到最近公共祖先
			}
		}
		return result;
	}
};

int main() {
	TreeNode a(3);
	TreeNode b(5);
	TreeNode c(1);
	TreeNode d(6);
	TreeNode e(2);
	TreeNode f(0);
	TreeNode x(8);
	TreeNode y(7);
	TreeNode z(4);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &x;
	e.left = &y;
	e.right = &z;

	Solution solve;
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &f);
	printf("lowestCommonAncestor = %d\n", result->val);
	TreeNode *result = solve.lowestCommonAncestor(&a, &d, &z);
	printf("lowestCommonAncestor = %d\n", result->val);
	TreeNode *result = solve.lowestCommonAncestor(&a, &b, &y);
	printf("lowestCommonAncestor = %d\n", result->val);
	return 0;
}

