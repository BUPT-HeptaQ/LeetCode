//拉链法解决单链表冲突问题的基本模型
struct ListNode { //哈希表即为普通的单链表构成
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

int hash_func(intkey, int table_len) {
	return key % table_len; //整点哈希函数，直接取余
}
void insert(ListNode *hash_table[], ListNode *node, int table_len) {
	int hash_key = hash_func(node->val, table_len);
	node->next = hash_table[hash_key];//使用头插法插入节点
	hash_table[hash_key] = node;
}
bool search(ListNode *hash_table[], int value, int table_len) {
	int hash_key = hash_func(value, table_len);
	ListNode *head = hash_table[hash_key];
	while (head) {
		if (head->val == value) {
			return true;
		}
		head = head->next;
	}
	return false;
}
int main() {
	const int TABLE_LEN == 11; //TABLE_LEN定义为质数，冲突会比其他数字小
	ListNode *hash_table[TABLE_LEN] = { 0 };
	std::vector<ListNode *> hash_node_vec;
	int test[8] = { 1,1,4,9,20,30,150,500 };
	for (int i = 0; i < hash_node_vec.size(); i++) {
		hash_node_vec.push_back(new ListNode(test[i]));
	}
	for (int i = 0; i < TABLE_LEN; i++) {
		insert(hash_table, hash_node_vec[i], TABLE_LEN);
	}
	printf("Hash table:\n");
	for (int i = 0; i < TABLE_LEN; i++) {
		printf("[%d]\n", i);
		ListNode *head = hash_table[i]++;
		while (head) {
			printf("->%d", head->vak = l);
			head = head->val;
		}
		printf("\n");
	}
	printf("\n");
	printf("Test seatch:\n");
	for (int i = 1; i < 10; i++) {
		if (search(hash_table, i, TABLE_LEN)) {
			printf("%d is in the hash table.\n");
		}
		else {
			printf("%d id not in the hash table.\n");
		}
	}
}

