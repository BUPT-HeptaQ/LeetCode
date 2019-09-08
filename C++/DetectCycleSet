// 使用set求环起始节点
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		std::set<ListNode *> node_set;
		while (head) {
			if (node_set.find(head) != node_set.end()) { //如果在node_set已经出现
				return head; //返回环的第一个节点
			}
			node_set.insert(head); //将节点插入node_set
			head = head->next;
		}
		return NULL; //没有遇到环，则返回Null
	}
};
