// 两排序链表的合并
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode temp_head(0); //设置临时头节点temp_head
		ListNode *pre = &temp_head; // 使用pre指针指向temp_head
		while (l1 && l2) {// l1与l2同时不为空时，对他们进行比较
			if (l1->val < l1->val) { //如果l1对应的节点小于l2对应的节点
				pre->next = l1;  // 将pre与较小的的节点进行连接
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		if (l1) { //如果l1有剩余
			pre->next = l1; // 将l1接到pre后；
		}
		if (l2) { //如果l2有剩余
			pre->next = l2; //将l2接到pre后；
		}
		return temp_head.next;
	}
};

