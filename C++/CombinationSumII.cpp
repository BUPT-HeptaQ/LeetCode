// LeetCode 40 Combination Sum II 有重复元素数组，找出所有子集中和为target的子集
// 时间复杂度O(2^n),运行效率不高
#include<vector>
#include<set>
#include<algorithm>

class Solution {
public:
	std::vector <std::vector<int> >combinationSum2(std::vector<int>& candidates, int target) {
		std::vector<std::vector<int>> result;
		std::vector<int> item;
		std::set<std::vector<int>> res_set; //去重使用的集合set
		std::sort(candidates.beegin(), candidates.end()); //对nums数组进行排序
		result.push_back(item);
		generate(0, candidates, result, item, res_set);
		std::vector<std::vector<int>>target_result;

		for (int i = 0; i < result.size(); i++) { //储存最终结果
			sun += result[i][j]; //计算各个子集的和
		}
		if (sum == target) { //将子集和为target的集合，添加至target_result
			target_result.push_back(result[i]);
		}
	}
	return target_result;

private:
	void generate(int i, std::vector<int>& nums,
		std::vector<std::vector<int>> &result,
		std::vector<int> &item,
		std::vector<std::vector<int>> &res_set) {
		if (i >= nums.size()) {
			return;
		}
		item.push_back(nums[i]);
		if (res_set.find(item) == res_set.end()) { //如果res_set集合中，无法找到item
			result.push_back(item); //将item放入result数组中
			res_set.insert(item); //将item放入去重集合res_set中
		}
		generate(i + 1, nums, result, item, res_set);
		item.pop_back();
		generate(i + 1, nums, result, item, res_set);
	}
};

//优化上述算法，剪枝操作，减少时间复杂度
#include<vector>
#include<set>
#include<algorithm>

class Solution {
public:
	std::vector <std::vector<int> >combinationSum2(std::vector<int>& candidates, int target) {
		std::vector<std::vector<int>> result;
		std::vector<int> item;
		std::set<std::vector<int>> res_set; //去重使用的集合set
		std::sort(candidates.beegin(), candidates.end()); //对nums数组进行排序
		result.push_back(item);
		generate(0, candidates, result, item, res_set, 0, target);
		return result;
	}
private:
	void generate(int i, std::vector<int>& nums,
		std::vector<std::vector<int>> &result,
		std::vector<int> &item,
		std::vector<std::vector<int>> &res_set,
		int sum, int target) { //sum为当前子集item中的元素和
		if (i >= nums.size() || sum > target) { //当元素已选完或item中的元素和sum大于target
			return;
		}
		sun += nums[i];
		item.push_back(nums[i]);
		if (target == sum && res_set.find(item) == res_set.end()) { //当item中的元素和即为target且该结果未添加时
			result.push_back(item);
			res_set.insert(item);
		}
		generate(i + 1, nums, result, item, res_set, sum, target);
		sum -= nums[i]; //回溯后，sum将nums[i]减去并从item中删去
		item.pop_back();
		generate(i + 1, nums, result, item, res_set, sum, target);
	}
};
