//2-2 LeetCode 142

int get_list_length(ListNode *head) {
	int len = 0;
	while (head) { // 遍历列表，计算链表长度
		len++;
		head = head->next;
	}
	return len;
}
ListNode *forward_long_list(int long_len, int short_len, ListNode *head) {
	int delta = long_len - short_len;
	while (head && delta) {
		head = head->next; //将指针向前移动至多出节点个数后边的位置
		delta--;
	}
	return head;
}
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int list_A_len = get_list_length(headA);
		int list_B_len = get_list_length(headB); // 求A、B两链表长度
		if (list_A_len > list_B_len) {
			headA = forward_long_list(list_A_len, list_B_len, headA);
		} // 如果A链表长，移动headA到对应位置
		else {
			headB = forward_long_list(list_B_len, list_A_len, headB);
		} //如果B链表长，则移动headB到对应位置 
		while (headA && headB) {
			if (headA==headB) { //当两个指针指向同一个节点，说明找到了共同节点
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
};
