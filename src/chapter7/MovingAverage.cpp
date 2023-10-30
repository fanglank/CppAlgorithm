// #include <deque>
#include <queue>
using namespace std;
namespace chapter7{
    class MovingAverage
{
private:
    queue<int> nums;
    int capacity;
    int sum;
public:
    MovingAverage(int size);
    double next(int val);
    ~MovingAverage();
};

MovingAverage::MovingAverage(int size)
{
    capacity = size;
    sum = 0;
}

double MovingAverage::next(int val) {
    nums.push(val);
    sum += val;
    if(nums.size() > capacity) {
        sum-=nums.front();
    }

    return (double) sum / nums.size();
}

MovingAverage::~MovingAverage()
{
}
}

