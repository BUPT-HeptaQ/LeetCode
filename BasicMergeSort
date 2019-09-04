//归并排序算法基本模型：先拆解成足够小的元素再合并

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

void merge_sort(std::vector<int> &vec) {
	if (vec.size()<2) {
		return; //当子问题足够小时，直接求解
	}
	int mid = vec.size() / 2; //对原问题进行分解
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2; //即对原数组拆分为两个规模相同的数组，在对他们进行求解
	for (int i = 0; i < mid; i++) {
		sub_vec1.push_back(vec[i]);
	}
	for (int i = mid; i < vec.size(); i++) {
		sub_vec2.push_back(vec[i]);
	}
	merge_sort(sub_vec1); //对拆解后的两个子问题进行求解
	merge_sort(sub_vec2);
	vec.clear();
	merge_sort_two_vec(sub_vec1, sub_vec2, vec);//将子问题的解进行合并
}

#include<stdlib.h>
#include<algorithm>
#include<assert.h>
int main() { //生成随机数组。利用std::sort测试归并排序
	std::vector<int> sub_vec1;
	std::vector<int> sub_vec2;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		int num = (rand()*rand()) % 100003;
		vec1.push_back(num); //将同样的随机数push进入vec1和vec2
		vec2.push_back(num);
	}
	merge_sort(vec1); //对vec1调用归并排序
	std::sort(vec2.begin(), vec2.end()); //对vec2调用库函数std::sort
	assert(vec1.size() == vec2.size());
	for (int i = 0; i < vec1.size(); i++) { //排序后，利用断言按顺序比较每个元素
		assert(vec1[i] == vec2[i]);
	}
	return 0;
}
