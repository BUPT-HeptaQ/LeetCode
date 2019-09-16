// 多链表暴力排序
#include <vector>
#include <algorithm> // STL排序算法std::sort
bool cmp(const ListNode *a, const ListNode *b) {
	return a->val < b->val;
}
int main() { //比较函数，对节点进行从小到大的排序
	ListNode a(3);
	ListNode b(2);
	ListNode c(5);
	ListNode d(0);
	std::vector<ListNode *> node_vec;
	node_vec.push_back(&a);
	node_vec.push_back(&b);
	node_vec.push_back(&c);
	node_vec.push_back(&d); //调用排序函数
	std::sort(node_vec.begin), node_vec.end(), cmp);
	for (int i = 0; i < node_vec.size(); i++) {
		printf("%d\n", node_vec[i]->val);
	}
	return 0;
}
class Solution {//暴力比较
public:
	ListNode* mergeKList(std::vector<ListNode*> &lists) {
		for (int i = 0; i < lists.size(); i++) { // 遍历k个链表，将节点全部添加至node_vec
			ListNode *head = lists[i];
			while (head) {
				node_vec, push_back(head);
				head = head->next;
			}
		}
		if (node_vec.size() == 0) {
			return NULL; //根据节点数值进行排序
		}
		std::sort(node_vec.begin(), node_vec.end(), cmp);
			for (int i = 1; i < node_vec.size(); i++) {
				node_vec[i - 1]->next = node_vec[i]; //连接新的链表
			}
			node_vec[node_vec.size() - 1]->next = NULL;
			return node_vec[0];		
	}
};

class Solution {
public:
	ListNode* mergeKList(std::vector<ListNode*>&lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		if (lists.size() == 1) {
			return lists[0]; //如果只有一个来lists，直接返回头指针
		}
		if (lists.size() == 2) { //  如果有两个lists，调用两个lists merge函数
			return mergeTwoLists(lists[0], lists[1]);
		}
		int mid = lists.size()/2
		std::vector<ListNode*>sub1_lists;
		std::vector<ListNode*>sub2_lists; // 拆分lists为两个lists
		for (int i = 0; i < mid; i++) {
			sub1_lists.push_back(lists[i]);
		}
		for (int i = mid; i < lists.size; i++) {
			sub2_lists.push_back(lists[i]);
		}
		ListNode *l1 = mergeKList(sub1_lists);
		ListNode *l2 = mergeKList(sub2_lists);
		return mergeTwoLists(l1, l2); // 分置处理

	}
};

