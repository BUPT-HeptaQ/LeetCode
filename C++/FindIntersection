// 2-1 找到两个链表的交点
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {
	}
};
class Solution {
public:
	LIstNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		std::set<ListNode*> node_set;
		while (headA) {
			node_set.insert(headA); //将链表A中的节点插入node_set
			headA = headA->next;
		}
		while (headB) {
			if (node_set.find(headB) != node_set.end()) {
				return headB;
			} //当在headB中找到第一个出现在node_set中的节点时
			headB = headB->next;
		}
		return NULL;
	}
};

#include <set>
	int main() { // O(nlogn)或者O（n）的方法判断两数组是否有相同元素
		std::set<int> test_set;
		const int A_LEN = 7;
		const int B_LEN = 8;

		int a[A_LEN] = { 5,1,4,8,10,1,3 };
		int b[B_LEN] = { 2,7,6,3,1,6,0,1 };

		for (int i = 0; i < A_LEN; i++) {
			test_set.insert(a[i]); //将数组a的元素插入set
		}
		for (int i = 0; i < B_LEN; i++) {
			if (test_set.find(b[i]) != test_set.end()) {
				printf("b[%d] = %d in array A.\n", i, b[i]);
			}
		}
		return 0;
	}
}
