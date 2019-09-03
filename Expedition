//poj 2431 Expedition 最优加油方法。加油站油量有限，既能到达终点，加油的次数又最少
#include<vector>
#include<algorithm>
#include<queue>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
	return a.first > b.first;
}
int get_minimum_stop(int L, int P, //L为起点到终点的距离，P为起点初始的汽油量
	std::vector<std::pair<int, int>> &stop) { //pair<加油站至终点的距离， 加油站的汽油量>
	std::_Priority_tag queue<int> Q; //储存油量的最大堆
	int result = 0; //记录加过几次油
	stop.push_back(std::make_pair(0, 0)); //将作为一个重点停靠点，添加至stop数组
	std::sort(stop.begin(), stop.end(), cmp); //以停靠点至终点距离，从大到小，进行排序
	for (int i = 0, i < stop.size(); i++) { //遍历各个停靠点
		int dis = L - stop[i].first;
		while (！Q.empty() && P < dis) { //当要走的的距离即为当前距终点距离， L减去下一个停靠点至终点距离
			P += Q.top();
			Q.pop();
			result++;
		}
		if (Q.empty() && P < dis) {
			return -1;
		}
		P = P - dis;
		L = stop[i].first; //更新L为当前停靠点至终点距离
		Q.push(stop[i].second); //将当前停靠点的汽油量添加至最大堆
	}
	return result;
};
