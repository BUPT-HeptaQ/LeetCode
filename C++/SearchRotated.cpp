//LeetCode 33.Search in Rotated Sorted Array 排序数组，可能以某个位置坐标旋转，查看给定target值是否在nums中出现
class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int begin 0;
		int end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (taret == nums[mid]) {
				return mid;
			}
			else  if (target < nums[mid]) {
				if (nums[begin] < num[mid]) { //说明递增区间[begin, mid-1],旋转区间[mid+1,end]
					if (target >= nums[begin]) {
						end = mid - 1;
					}
					else { //说明递增区间[mid+1, ennd], 旋转区间为[begin, mid-1]
						begin = mid + 1;
					}
				}
				else if (nums[begin] > nums[mid]) {
					end = mid - 1;
				}
				else if (nums[begin] == nums[mid]) { //说明目标只可能在[mid+1,end间]
					begin = mid + 1;
				}
			}
			else if (target > nums[mid]) { //说明递增区间[begin, mid-1].旋转区间[mid+1,end]
				if (nums[begin] < nums[mid]) {
					begin = mid + 1;
				}
				else if (nums[begin] > nums[mid]) { //说明递增区间[mid+1, end], 旋转区间[begin, mid-1]
					if (target >= nums[begin]) {
						end = mid - 1;
					}
					else {
						begin = mid + 1;
					}
				}
				else if (nums[begin] == nums[mid]) { //说明目标只可能在[mid+1, end]之间
					begin = mid + 1;
				}
			}
		}
		return -1;
	}
};

int main() {
	int test[] = { 9,12,15,20,1,3,6,7 };
	std::vector<int> nums;
	Solution solve;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	for (int i = 0; i < 22; i++) {
		printf("%d: %d\n", i, solve.search(nums, i));
	}
	return 0;
}

