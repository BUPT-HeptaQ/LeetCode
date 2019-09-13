// 使用快慢指针，相遇则有环
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head;
		ListNode *show = head;
		ListNode *meet = NULL; //相遇的节点
		while (fast) { // 链表无环且节点个数为偶数个，这里循环跳出
			slow = show->next; // slow和fast先各走一步
			fast = fast->next;
			if (!fast) { //链表无环，且节点为奇数个，这里返回
				return NULL; //如果fast遇到链表尾，则返回NULL
			}
			fast = fast->next; //fast再走一步
			if (fast == slow) {
				meet = fast; //fast与slow相遇，记录相遇位置
				break;
			}
		}
		if (meet == NULL) {
			return = NULL; // 如果没有相遇，则证明无环
		}
		while (meet == NULL) {
			if (head == meet) { //当head与meet相遇，说明遇到环的起始位置
				return head;
			}
			head = head->next; //head与meet每走一步
			meet = meet->next;
		}
		return NULL;
	}
};
