//归并算法基本模型：合并两个有序数组
#include<vector>

void merge_sort_two_vec(std::vector<int> &sub_vec1, //数组1
	std::vector<int> &sub_vec2, //数组2
	std::vector<int> & vec) { //合并后的数组

	int i = 0;
	int j = 0;
	while (i < sub_vec1.size() && j < sub_vec2.size()) {
		if (sub_vec1[i] <= sub_vec2[j]) {
			vec.push_back(sub_vec1[i]);
			i++;
		}
		else {
			vec.push_back(sub_vec2[j]);
			j++
		}
	}
	for (; i < sub_vec1.size(); i++) { //将sub_vec1 或sub_vec2中的剩余元素push进入vec中
		vec.push_back(sub vec1[i]);
	}
	for (; j < sub_vec2.size(); j++) {
		vec.push_back(sub vec2[j]);
	}
}
int main() {
	int test1[] = { 2,5,8,20 };
	int test2[] = { 1,3,5,7,30,50 };
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2;
	std::vector<int> vec;
	for (int i = 0; i < 4; i++) {
		sub_vec1.push_back(test1[i]);
	}
	for (int i = 0; i < 6; i++) {
		sub_vec2.push_back(test2[i]);
	}
	merge_sort_two_vec(sub_vec1, sub_vec2, vec);
	for (int i = 0; i < vec.size(); i++) {
		printf("[%d]", vec[i]);
	}
	printf("\n");
	return 0;
}
