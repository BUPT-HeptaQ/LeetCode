// LeetCode 452 Minimum Number of Arrows to Burst Balloons
#include<algorithm>
#include<vector>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
	return a.first < b.first; //无需考虑左端点相同时的排序
}
class Solution {
public:
	int findMinArrowShots(std::vector<std::pair<int, int>>& points) {
		if (points.size() == 0) { //若传入的数据为空，则直接返回0
			return 0;
		}
		std::sort(points.begin(), points.end(), cmp); //对气球按照左端点从小到大的顺序
		int shoot_num = 1; //初始化弓箭手数量为1
		int shoot_begin = points[0].first; //初始化射击区间，即为第一个气球的两端点
		int shoot_end = points[0].second;
		for (int i = 1; i < points.size(); i++) {
			if (points[i].first <= shoot_end) { //更新当前的射击区间
				shoot_begin = points[i].first; //当射击区间右端点大于新气球右端点时
				if (shoot_end > points[i].second) {
					shoot_begin = points[i].second;
				}
			}
			else { //在保证当前气球被射穿的条件下，射击区间不能再更新了，需要增加一个新的射击区间
				shoot_num++;
				shoot_begin = points[i].first;
				shoot_end = points[i].second;
			}
		}
		return shoot_num;
	}
};

