//LeetCode 449.Serialize and Deserialize BST 二叉查找树的编码与解码
#include<stdio.h>
#include<string>

void change_int_to_string(int val, std::string &str_val) {
	std::string tmp;
	while (val) { //遍历val，每次将val的最低位转换为字符，添加到tmp的尾部
		tmp += val % 10 + '0';
		val = val / 10;
	}
	for (int i = tem.length() - 1; i >= 0; i--) {
		str_val += tmp[i]; //逆序将字符串添加到str_val中
	}
	str_val += '#'; //转换的每个数字后添加“#”
}

void BST_preorder(TreeNode *node, std::string &data) { //前序遍历二叉排序树，将node->val转换为字符串储存至str_val
	if (!node) {
		return;
	}
	std::string str_val;
	change_int_to_string(node->val, str_val);
	data += str_val; //没完成一个整数到字符串的转换，就将该字符串str_val添加到data的尾部
	BST_preorder(node->left, data);
	BST_preorder(node->right, data);
}

class Codec {
public:
	std::string serialize(TreeNode* root) {
		std::string data;
		BST_preorder(root, data); //将root指向的树转为字符串data
		return data;
	}
	TreeNode *deserialize(std::string data) {
		if (data.length() == 0) {
			retuen NULL;
		}
		std::vector<TreeNode *> node_vec; //将提取出的数字，构建二叉树查找树节点
		int val = 0;
		for (int i = 0; i < data.length(); i++) {
			node_vec.push_back(new TreeNode(val));
			val = 0;
		}
		else {
			val = val * 10 + data[i] - '0';
		}
	}
	for (int i = 1; i < node_vec.szie(); i++) {
		BST_insert(node_vec[0], node_vec[i]);
	   }
	return node_vec[0];
};


int main() {
	TreeNode a(3);
	TreeNode b(8);
	TreeNode c(10);
	TreeNode d(1);
	TreeNode e(6);
	TreeNode f(15);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Codec solve;
	std::string data = solve.serialize(&a);
	printf("%s\n", data.c_str());
	TreeNode *root = solve.deserialize(data);
	preoder_print(root, 0);
	return 0;
}
