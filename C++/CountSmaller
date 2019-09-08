//LeetCode 315.Count of Smaller Numbers After Self
//新数组count，count[i]代表了在nums[i]右侧且比nums[i]小的元素个数
#include<vector>

class Solution {
public:
	std::vector<int> countSmaller(std::vector<int>& nums) {
		std::vector<std::pair<int, int>>vec;
		std::vector<int> count;
		for (int i = 0; i < nums.size(); i++) {
			vec.push_back(std::make_pair(nums[i], i));
			count.push_back(0);
		} //将nums[i]与i绑定为pair<nums[i], i>
		merge_sort(vec, count);
		return count;
	}
private: 
	void merge_sort_two_vec(std::vector<int> &sub_vec1, //数组1
			std::vector<int> &sub_vec2, //数组2
			std::vector<int> & vec, //合并后的数组
			std::vector<int> &count) { 

			int i = 0;
			int j = 0;
			while (i < sub_vec1.size() && j < sub_vec2.size()) {
				if (sub_vec1[i].first <= sub_vec2[j],first) {
					count[sub_vec1[i].second] += j;
					vec.push_back(sub_vec1[i]);
					i++;
				}
				else {
					vec.push_back(sub_vec2[j]);
					j++
				}
			}
			for (; i < sub_vec1.size(); i++) { //将sub_vec1 或sub_vec2中的剩余元素push进入vec中
				count[sub_vec1[i].second] += j;
				vec.push_back(sub vec1[i]);
			}
			for (; j < sub_vec2.size(); j++) {
				vec.push_back(sub vec2[j]);
			}
	}
    
    void merge_sort(std::vector<std::pair<int, int>> vec,
			std::vector<int> &count) {
		if (vec.size() < 2) { //当子问题足够小时，直接求解
			return;
		}
		int mid = vec.size() / 2;
		std::vector<std::pair<int, int>> sub_vec1; //对原问题进行分解
		std::vector<std::pair<int, int>> sub_vec2;
		for (int i = 0; i < mid; i++) { //即对原数组拆分为两个规模相同的数组，在对他们进行求解
			sub_vec1.push_back(vec[i]);
		}
		for (int i = mid; i < vec.size(); i++) {
			sub_vec2.push_back(vec[i]);
		}
		merge_sort(sub_vec1, count);
		merge_sort(sub_vec2, count); //对拆解后的两个子问题进行求解
		vec.clear();
		merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
	}
};
