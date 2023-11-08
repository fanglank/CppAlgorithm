#include <queue>
#include <vector>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

// auto cmp = [](const pair<int, int> p1, const pair<int, int> p2) { return p1.second > p2.second; };
struct cmp {
    bool operator() ( const pair<int, int> p1 , const pair<int, int> p2 ){//默认是less函数
        //返回true时，a的优先级低于b的优先级（a排在b的后面）
        return p1.second > p2.second;
    }
};
vector<int> topKFrequent(vector<int> nums, int k) {
    unordered_map<int, int> numToCount;
    for(int item : nums){
        numToCount[item] = numToCount[item] + 1;
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, cmp > minHeap;
    for(auto item: numToCount) {
        if(minHeap.size() < k) {
            minHeap.push(make_pair(item.first, item.second));
        }else {
            if(item.second > minHeap.top().second){
                minHeap.pop();
                minHeap.push(make_pair(item.first, item.second));
            }
        }
    }

    vector<int> result;

    while (!minHeap.empty()){
        result.push_back(minHeap.top().second);
        minHeap.pop();
    }
    return result;
}