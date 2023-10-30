#include <vector>
#include <limits>
using namespace std;

int helper(vector<int> heights, int start, int end) {
    if(start == end) {
        return 0;
    }
    if(start +1 == end) {
        return heights[start];
    }
    int minIndex = start;
    for(int i = start +1;i< end; i++) {
        if(heights[i] < heights[minIndex]) {
            minIndex = i;
        }
    }
    int area = (end -start)* heights[minIndex];
    int left = helper(heights, start, minIndex);
    int right = helper(heights, minIndex+1, end);
    area = max(area, left);
    return max(area, right);
}

int largestRectangleArea(vector<int> heights) {
    return helper(heights, 0, heights.size());
}