// leetcode 295 Find median from data stream
// 利用最大堆和最小堆每个堆正好有数据集的一半， 两个堆的堆顶正好是中位数，元素多一的堆的堆顶为中位数
void addNum(int num) {
	if (big_queue.empty()) {//big_queue最大堆
		big_queue.push(num); // small_queue最小堆
		return;
	}
	if (big_queue.size() == small_queue.size()) {
		if (num<=big_queue.top()) {
			big_queue.push(num);
		}
		else {
			small_queue.push(num);
		}
	}
	else if (big_queue.size()>small_queue.size()) {
		if (num > big_queue.top()) {
			small_queue.push(num);
		}
		else {
			small_queue.push(big_queue.top());
			big_queue.pop();
			big_queue.push(num);
		}
	}
	else if (big_queue.size()<small_queue.size()) {
		if (num<small_queue.top()) {
			big_queue.push(num);
		}
	    else {
			big_queue.push(small_queue.top());
			small_queue.pop();
			small_queue.push(num);
		}
	}
};
double findMedian() {
	if (big_queue.size()==small_queue.size()) {
	    return (big_queue.top()+small_queue.top())/2
	}
	else if (big_queue.size()>small_queue.size()) {
		return big_queue.top();
	}
	return small_queue.top();
}
