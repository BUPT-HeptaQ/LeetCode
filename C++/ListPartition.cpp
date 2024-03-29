// 链表划分 用临时头节点
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode less_head(0); // 设置两个临时头节点
		ListNode more_head(0);
		ListNode *less_ptr = &less_head; // 对应指针指向这两个头节点
		ListNode *more_ptr = &more_head;

		while (head) {
			if (head->val < x) { //如果节点值小于x，则该节点插入less_ptr后
				less_ptr->next = head;
				less_ptr = head; // 链接完成以后，less_ptr向后移动，指向head
			}
			else { // 否则将该节点插入more_ptr后
				more_ptr->next = head;
				more_ptr = head;
			}
			head = head->next; // 遍历链表
		}
		less_ptr->next = more_head.next; // 将less链表尾与more链表头相连接
		more_ptr->next = NULL; // 将more_ptr即链表尾节点next置空
		return less_head.next; // less_head的next节点即为新链表的头节点，返回
	}
};

