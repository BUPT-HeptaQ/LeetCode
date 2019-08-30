// 复杂链表的深度拷贝
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x); label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
	
	} // 返回深度拷贝后的列表
}; // 深度拷贝：构造一个完全新的链表，即使将原链表毁坏，新链表可独立使用

}

// STL Map 的使用
#include <stdio.h>
#include <map>

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(Null) {}
};
int main() {
std:map<RandomListNode *, int>node_map;
	RandomListNode a(5); // 设置一个节点map，key为地址，value为整型
	RandomListNode b(3);
	RandomListNode c(6);
	a.next = &b;
	b.next = &c;
	a.random = &c;
	b.random = &a;
	c.random = &c;
	node_map[&a] = 1;
	node_map[&b] = 2;
	node_map[&c] = 3;
	printf("a.random id = %d\n", node_map[a.random]);
	printf("b.random id = %d\n", node_map[b.random]);
	printf("c.random id = %d\n", node_map[c.random]);
	return 0;
}

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		std::map<RandomListNode *, int>node_map;
		std::vector<RandomListNode *> node_vec;
		RandomListNode *ptr = head; // 使用vector根据储存节点位置访问地址
		int = 0;
		while (ptr) {
			node_vec.push_back(new RandomListNode(ptr->label));
			node_map[ptr] = i; // 记录原始链表地址至节点位置的node_map
			ptr = ptr->next; //遍历原始列表
			i++; //i记录节点位置
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0; //再次遍历原始列表，链接新的链表的next指针、random指针
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1]; //链接新链表next指针
			if (ptr->random) { //当random指针不空时
				int id = node_map[ptr->random]; //根据node_map确认，原链表random指针指向的位置即id
				node_vec[i]->random = node_vec[id]; //链接新链表的random指针
			}
			ptr = ptr->next;
			i++;
		}
		return node_vec[0];
	}
};
