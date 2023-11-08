#include <queue>
#include <vector>
using namespace std;
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int size;
public:
    KthLargest(int k, vector<int> nums);
    int add(int val);
    ~KthLargest();
};

KthLargest::KthLargest(int k, vector<int> nums)
{
    size = k;
    
}

int KthLargest::add(int val) {
    if(minHeap.size() < size) {
        minHeap.push(val);
    }else if(val > minHeap.top()){
        minHeap.pop();
         minHeap.push(val);
    }
    return minHeap.top();
}

KthLargest::~KthLargest()
{
}
