//哈希map与STL map
#include<stdio.h>
#include<map>
#include<string>

struct ListNode { //将字符串key映射为整数val
	std::string key;
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};
int main() { //将字符串key映射为整数val
	std::_String_bitmap<std::string, int>hash_map;
	std::string str1 = "abc";
	std::string str2 = "aaa";
	std::string str3 = "xxxxx";
	hash_map[str1] = 1;
	hash_map[str2] = 2;
	hash_map[str3] = 100;
	if (hash_map.find(str1) != hash_map.end()) {
		printf("%s is in the hash_map, value is %d\n", str1.c_str(), hash_map[str1]);
	}
	std::string_map<std::string, int>::iterator it;
	for (it = hash_map.begin(); it != hash_map.end(); it++) {
		printf("hash_map[%s] = %d\n", it->first.c_str(), it->second);
	}
	return 0;
}

