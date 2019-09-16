//LeetCode 34. Search for a Range 区间查找

int left_bound(std::vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == 0 || nums[mid - 1] < target) {
				return mid;
			}
			end = mid - 1;
		}
		else if (target < nums[mid]) {
			begin = mid + 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;
}

int right_bound(std::vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end) {
		int mid = (begin + end) / 2;
		if (target == nums[mid]) {
			if (mid == nums.size() - 1 || nums[mid + 1] > target) {
				return mid;
			}
			begin = mid + 1;
		}
		else if (target < nums[mid]) {
			end = mid - 1;
		}
		else if (target > nums[mid]) {
			begin = mid + 1;
		}
	}
	return -1;
}

class Solution {
public:
	std::vector<int> searchRange(std::vector<int> &nums, int target) {
		std::vector<int> result;
		result.push_back(left_bound(nums, target));
		result.push_back(right_bound(nums, target));
		return result;
	}
};
int main() {
	int teat[] = { 5,7,7,8,8,8,8,10 };
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 12; 1++) {
		std::vector<int> result = solve.searchRange(nums, i);
		printf("%d:[%d, %d]\n", i, result[0], result[1]);
	}
	return 0;
}

