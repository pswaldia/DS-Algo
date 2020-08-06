#include<bits/stdc++.h>
using namespace std;


class MedianFinder {
public:
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	int count;
	MedianFinder() {
		max_heap = priority_queue<int>();
		min_heap = priority_queue<int, vector<int>, greater<int> >();
		count = 0;
	}
	void addNum(int num) {
		if (count == 0)
			max_heap.push(num);
		else if (num > max_heap.top())
			min_heap.push(num);
		else
			max_heap.push(num);
		count += 1;
		if (max_heap.size() > 1 + min_heap.size()) {
			min_heap.push(max_heap.top());
			max_heap.pop();
		} else if (min_heap.size() > max_heap.size()) {
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
	}
	double findMedian() {
		if (count % 2 == 0)
			return (double)(max_heap.top() + min_heap.top()) / 2;
		else
			return max_heap.top();
	}
};
