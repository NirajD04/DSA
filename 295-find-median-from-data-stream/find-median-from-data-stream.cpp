class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int, vector<int>, greater<int>> right_min_heap;
    MedianFinder() {}

    void addNum(int num) {
        if (left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }

        if (abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if (left_max_heap.size() < right_min_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    double findMedian() {
        if (left_max_heap.size() == right_min_heap.size()) {
            int mean=left_max_heap.top() + right_min_heap.top();
            return mean / 2.0;
        } else {
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//  // do heap  le max and min
//  if odd number of elemtn return top of max heap
//  else return top of max  + min ka avg
// always max heap me jada element rehege
// push kese karna first elemtn in max heap, then if next elemnt is greatert he
// top of max push it in min heap
