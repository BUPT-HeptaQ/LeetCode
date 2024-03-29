// LeetCode 55 Jump Game
#include<vector>
class Solution {
public:
	bool canJump(std::vector<int>& nums) {
		std::vector<int> index; //可跳至最远的位置
		for (int i = 0; i < nums.size(); i++) {
			index.push_back(i + nums[i]); //计算index数组
		}
		int jump = 0; //初始化jump与max_index
		int max_index = index[0];
		while (jump < index.size()&&jump<=max_index) { //直到jump跳至数组尾部或jump超越当前可以跳的最远位置
			if (max_index < index[jump]) {
				max_index = index[jump]; //如果当前跳的更远，则更新max_index
			}
			jump++; //扫描jump
		}
		if (jump == index.size()) { //若jump达到数组尾，则返回真
			return true;
		}
		return false; //否则返回假
	}
};

