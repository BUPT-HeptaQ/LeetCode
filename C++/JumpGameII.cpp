// LeetCode 45 Jump Game II
#include<vector>
class Solution {
public:
	int jump(stad::vector<int>& nums) {
		if (nums.size() < 2) { //如果数组长度小于2，则说明不用跳跃，返回0
			return 0;
		}
		int current_max_index = nums[0]; //当前可达到最远的位置
		int pre_max_max_index = num[0]; //遍历各个位置的过程中，可达到最远的位置
		int jump_min = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (i > current_max_index) { //若无法在向前移动，才进行跳跃
				jump_min++; 
				current_max_index = pre_max_max_index; //即更新当前可达到的最远位置
			}
			if (pre_max_max_index < nums[i] + i) {
				pre_max_max_index = nums[i] + i; //更新pre_max_max_index
			}
		}
		return jump_min;
	}
};

