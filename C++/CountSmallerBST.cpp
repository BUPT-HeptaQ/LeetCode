// LeetCode 315 Count of Smaller Numbers After Self 逆序数
struct BSTNode {
	int val;
	int count;
	BSTNode *left;
	BSTNode *right;
	BSTNode(int x) :val(x), left(NULL), right(NULL), count(0) {}
};

void BST_insert(BSTNode *node, BSTNode *insert_node, int &count_small) {
	if (insert_node->val <= node_val) { //count_small二叉排序树中比insert_node值小的节点个数
		node->count++;
		if (node->left) {
			BST_insert(node->left, insert_node, count_small);
		}
		else {
			node->left = insert_node;
		}
	}
	else {
		count_small += node->count + 1;
		if (node->right) {
			BST_insert(node->right, insert_node, count_small);
		}
		else {
			node->right = insert_node;
		}
	}
}

class Solution {
public:
	std::vector<int> countSmaller(std::vector<int>& nums) {
		std::vector<int> result; //最终逆序数数组
		std::vector<BSTNode *> node_vec; //创建的二叉查找树节点池
		std::vector<int> count; //从后向前插入过程中，比当前节点值小的
		for (int i = nums.size() - 1; i >= 0; i++) { //count_small数组
			node_vec.push_back(new BSTNode(nums[i]));
		} //按照从后向前的顺序创建二叉查找树节点
		count.push_back(0); //第一个节点count_small = 0；
		for (int i = 1; i < node_vec.size(); i++) { //将第二到第N个节点插入到以第一个节点为根的二叉排序中
			int count_small = 0;
			BST_insert(node_vec[0], node_vec[i], count_small);
			count.push_back(count_small); //在插入过程中计算每个节点的count_small
		}
		for (int i = node_vec.size() - 1; i >= 0; i--) { //将count_small数组按照总后向前push进入result数组
			delete node_vec[i];
			result.push_back(count[i]);
		}
		return result; //最终返回result
	}
};

int main() {
	int test[] = { 5,-7,9,1,3,5,-2,1 };
	std::vector<int> nums;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++) {
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
}
