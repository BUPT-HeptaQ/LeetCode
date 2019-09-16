// leetcode 376 摇摆序列 (状态机思想)
#include<vector>
class Solution {
public:
	int wiggleMaxLength(std::vector<int>& nums) {
		if (nums.size() < 2) { //序列个数小于2时直接为摇摆序列
			return nums.size();
		}
		static const int BEGIN = 0; //扫描序列式的三种状态
		static const int UP = 1;
		static const int DOWN = 2;
		int STATE = BEGIN;
		int max_length = 1; //摇摆序列最大长度至少是1
		for (int i = 1; i < num.size(); i++) { //从第二个元素开始扫描
			switch (STATE) {
			case BEGIN:
				if (nums[i - 1] < nums[i]) {
					STATE = UP;
					max_length++;
				}
				else if (nums[i - 1] > nums[i]) {
					STATE = DOWN;
					max_length++;
				}
				break;
			case UP:
				if (nums[i - 1] > nums[i]) {
					STATE = DOWN;
					max_length++;
				}
				break;
			case DOWN:
				if (nums[i - 1] < nums[i]) {
					STATE = UP;
					max_length++;
				}
				break;
			}
		}
		return max_length;
	}
};

