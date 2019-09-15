struct ListNode{
	int val;
	ListNode *next;
	ListNode(int *x) :val(x), next(NULL) {}
};

// 逆置链表中的所有节点
class Solution{
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head = NULL;
		while (head)
		{
			ListNode *next = head->next; //备份head->next
			head->next = new_head; //更新head->next
			new_head = head; //移动new_head
			head = next; //遍历链表
		}
		return new_head; //返回新链表头节点
	}
};

