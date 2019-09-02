// 1. leet code 455
#include<vector>
#include<algorithm>
class Solution{
public:
	int findContentChilden(std::vector<int>& g, std::vector<int> &s) {
		std::sort(g.begin(), g.end());
		std::sort(s.begin(), s.end()); //对孩子的需求因子g与糖果大小s两数组排序
		int child = 0;
		int cookie = 0; //child代表满足了几个孩子，cookie代表尝试了几个糖果
		while (child < g.size() && cookie < s.size()) { // 当孩子或糖果同时均未尝试完成时
			if (g[child] <= s[cookie]) { //当孩子的满足因子小于或等于糖果大小时
				child++; //该糖果满足了孩子，孩子指针child向后移动
			}
			cookie++; //无论成功或失败，每个糖果只尝试一次，cookie向后移动
		}
		return child; //最终child即为得到满足孩子的个数
	}
};
