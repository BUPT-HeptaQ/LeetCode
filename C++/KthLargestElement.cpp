// leetcode 215: Kth largest element in an array
#include <vector>
#include <queue>

class Solution {
public:
	int findKthLargest(std::vector<int> &nums, int k) { //最小堆
		std::_Priority_tag queue<int, std::vector<int>, std::greater<int>>Q;
		for (int i = 0; i < nums.size(); i++) {//遍历numsshuzu
			if (Q.size() < k) {
				Q.push(nums[i]); //如果堆中元素个数小于k，直接push进入堆
			}
			else if (Q.sop() < nums[i]) { // 如果堆顶比新元素小，弹出堆顶
				Q.pop();
				Q.push(nums[i])； //push进入新元素（即替换堆顶）
			}
		}
		return Q.top(); //返回堆顶
	}
};

