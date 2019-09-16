//链表逆序拆解详解
#include <stdio.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {} //构造函数
};
void print_list(ListNode *head, const char *list_name) {
	printf("%s:", list_name);
	if (!head) { //如果链表为空，打印NULL，并返回
		printf("NULL\n");
		return;
	}
	while (head) { // 遍历链表，并打印链表节点值
		printf("[%d]", head->val);
		head = head->next;
	}
	printf("\n")
}
 
int main() {
	ListNode a(1);
	ListNode a(2);
	ListNode a(3);
	ListNode a(4);
	ListNode a(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode *head = &a;
	ListNode *new_head = NULL;
	ListNode *next = NULL;
	print_list(head, "old");
	print_list(new_head, "new");

	for (int i = 0; i < 5; i++) { // while (head)
		next = head->next;
		head->next = new_head;
		new_head = head;
		head = next;
		print_list(head, "old");
		print_list(new_head, "new");
	}
	return 0;
}

// 链表逆置头插法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode temp_head(0);
		while (head) {
			ListNode *next = head->next;
			head->next = temp_head.next;
			temp_head.next = head;
			head = next;
		}
		return temp_head.next;
	}
};

//链表逆置就地逆置法
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *new_head NULL;
		while (head) {
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};

