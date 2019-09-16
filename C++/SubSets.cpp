// LeetCode 78 Subsets 求所有无重复元素数组的子集
//回溯法初步 nums[] = [1,2,3], 将子集[[1],[1,2],[1,2,3]]打印出来
#include<stdio.h>
#include<vector>

int main() {
	std::vector<int>nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);

	std::vector<int> item; //item，生成各个子集的数组
	std::vector<std::vector<int>> result; //result，最终结果数组
	generate(0, nums, item, result);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void generate(int i, std::vector<int>& nums,
	std::vector<int> &item,
	std::vector<std::vector<int>> &result) {
	if (i >= nums.size()) { //递归结束条件，当i下标超过nums数组长度时，结束递归
		return;
	}
	item.push_back(nums[i]);
	result.push_back(item);
	generate(i + 1, nums, item, result);
}

//回溯法完整实现 nums[] = [1,2,3], 将子集[[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3]]打印出来
#include<vector>
class Solution {
public:
	std::vector<std::vector<int>>subsets(std::vector<int> &nums) {
		std::vector<std::vector<int>> result; //储存最终结果的result
		std::vector<int> item; //回溯时，产生各个子集的数组
		result.push_back(item); //将空集push进入result
		generate(0, nums, item, result); //计算各个子集
		return result;
	}
private:
	void generate(int i, std::vector<int>& nums,
		std::vector<int> &item,
		std::vector<std::vector<int>> &result) {
		if (i >= nums.size()) {
			return;
		}
		item.push_back(nums[i])
		result.push_back(item); //将当前生成子集添加进入result
		generate(i + 1, nums, item, result); //第一次调用递归
		item.pop_back();
		generate(i + 1, nums, item, result); //第二次调用递归
	}
};

//位运算法的完整实现
#include<vector>
class Solution {
public:
	std::vector<std::vector<int>>subsets(std::vector<int>& nums) {
		std::vector<std::vector<int>> result;
		int all_set = 1 << nums.size(); //设置全部集合的最大值+1, 1<<n 即为2^n
		for (int i = 0; i < all_set; i++) { //遍历所有集合
			std::vector<int> item;
			for (int j = 0; j < nums.size(); j++) {
				if (i & (1 << j)) { //构造数字i代表的集合，各个元素储存至item
					item.push_back(nums[j]); //(1 << j)即为构造nums数组的第j个元素
				} //整数i代表从0至2^n-1这2^n个合集
			}
			result.push_back(item); //若i &(1 << j)为真，则nums[j]放入item
		}
		return result;
	}
};

