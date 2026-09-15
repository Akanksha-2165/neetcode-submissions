class MedianFinder {
public:
    MedianFinder() {
        
    }

    priority_queue<int> left; //maxheap
    priority_queue<int, vector<int>, greater<int>> right; //minheap
    
    void addNum(int num) {

        if(left.empty() || num <= left.top())
            left.push(num);

        else
            right.push(num);

        //balancing heap
        if(left.size() > right.size() + 1)  {
            right.push(left.top());
            left.pop();
        }

        else if(right.size() > left.size()+1)    {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        
        else if(right.size() > left.size())
            return right.top();

        else
            return (left.top() + right.top()) / 2.0;
    }
};

// BRUTE FORCE - Store and Sort
// Store every number in a vector.
// Whenever findMedian() is called, sort the vector
// and take the middle element(s).
// Time Complexity: O(N log N) for each findMedian()    Space Complexity: O(N)

// OPTIMAL - Two Heaps
// Use a maxHeap for the smaller half and a minHeap for the larger half.
// Keep both heaps balanced so their sizes differ by at most 1.
// maxHeap.top() gives the largest value of the smaller half,
// and minHeap.top() gives the smallest value of the larger half.
// These are exactly the two middle values needed for the median.
// For odd number of elements, return the top of the larger heap.
// For even number of elements, return the average of both heap tops.
// Time Complexity: O(log N) for addNum(), O(1) for findMedian()     Space Complexity: O(N)